create database rally;
use rally;

CREATE TABLE Categorie(
	idCategorie int PRIMARY KEY,
	Categorie Varchar(100)
)
go
CREATE TABLE Pilot (
  IdPilot int PRIMARY KEY,
  Name Varchar(100),
 idCategorie int REFERENCES Categorie(idCategorie)
)
go

CREATE TABLE Race (
  IdRace int PRIMARY KEY,
  RaceName Varchar(100)
)
go

CREATE TABLE Game (
  IdGame int PRIMARY KEY,
  GameName Varchar(100) UNIQUE
)
go

CREATE TABLE Event (
  IdEvent int PRIMARY KEY,
  IdGame int REFERENCES Game(IdGame),
  IdRace int REFERENCES Race(IdRace),
  IdPilot int REFERENCES Pilot(IdPilot),
  Temps Time
)
go


CREATE OR REPLACE VIEW RankedPilotesView AS
SELECT course.idRallye, 
       p.nomPilote,
       p.idPilote, 
       p.idCategorie as idCategorieRanked,
       p.intitulerCategorie as categorie 
       CONVERT(TIME, DATEADD(SECOND, SUM(DATEDIFF(SECOND, '00:00:00', course.Temps)), '00:00:00')) AS TempsTotal,
       DENSE_RANK() OVER (PARTITION BY course.idRallye ORDER BY CONVERT(TIME, DATEADD(SECOND, SUM(DATEDIFF(SECOND, '00:00:00', course.chronometre)), '1900-01-01')) ASC) AS Rank
FROM Course course
JOIN Pilote p ON course.idPilote = p.idPilote
GROUP BY course.idRallye, p.idPilote, p.nomPilote, p.idCategorie;


CREATE VIEW RankedPilotesViewCategorie AS
SELECT e.IdGame, 
       p.Name,
       p.IdPilot, 
       p.idCategorie as idCategorieRanked, 
       CONVERT(TIME, DATEADD(SECOND, SUM(DATEDIFF(SECOND, '00:00:00', e.Temps)), '00:00:00')) AS TempsTotal,
       DENSE_RANK() OVER (PARTITION BY e.IdGame, p.idCategorie ORDER BY CONVERT(TIME, DATEADD(SECOND, SUM(DATEDIFF(SECOND, '00:00:00', e.Temps)), '00:00:00')) ASC) AS Rank
FROM Event e
JOIN Pilot p ON e.IdPilot = p.IdPilot
GROUP BY e.IdGame, p.IdPilot, p.Name, p.idCategorie;


/********************/
/*I- General result*/
CREATE VIEW Result AS  
SELECT g.IdGame,
       RankedPilotesView.IdPilot,
       g.GameName as GameName,
       Name,
       Categorie.Categorie as Categorie,
       TempsTotal,
       Rank,
       CASE
         WHEN Rank = 1 THEN 25
         WHEN Rank = 2 THEN 24
         WHEN Rank = 3 THEN 23
         WHEN Rank = 4 THEN 22
         WHEN Rank = 5 THEN 21
         WHEN Rank = 6 THEN 20
         WHEN Rank = 7 THEN 19
         WHEN Rank = 8 THEN 18
         WHEN Rank = 9 THEN 17
         WHEN Rank = 10 THEN 16
         ELSE 0
       END AS Points
FROM RankedPilotesView 
LEFT JOIN Game g ON RankedPilotesView.IdGame = g.IdGame 
JOIN Categorie ON RankedPilotesView.idCategorieRanked = Categorie.idCategorie;

	/*Calculate points based on rank*/
	CREATE  VIEW Isa AS SELECT count(DISTINCT(Result.IdPilot)) as PilotNumber,count(DISTINCT(Result.IdGame)) as GameNumber from Result;
	SELECT Rank, Name, TempsTotal, (SELECT CASE WHEN Rank <=10 THEN PilotNumber - Rank ELSE 0 END AS Points FROM Isa) AS Points, GameName 
FROM Result ;

	/*just give points*/
	SELECT Rank ,Name,TempsTotal,Points,GameName FROM Result;






/***************************/
/*II General Result By Categotie*/
CREATE VIEW ResultCategorie AS  SELECT g.IdGame,RankedPilotesViewCategorie.idCategorieRanked,RankedPilotesViewCategorie.IdPilot, g.GameName as GameName, Name, Categorie.Categorie as Categorie, TempsTotal, Rank,
       CASE
         WHEN Rank = 1 THEN 25
         WHEN Rank = 2 THEN 24
         WHEN Rank = 3 THEN 23
         WHEN Rank = 4 THEN 22
         WHEN Rank = 5 THEN 21
         WHEN Rank = 6 THEN 20
         WHEN Rank = 7 THEN 19
         WHEN Rank = 8 THEN 18
         WHEN Rank = 9 THEN 17
         WHEN Rank = 10 THEN 16
         ELSE 0
       END AS Points
FROM RankedPilotesViewCategorie LEFT JOIN Game g ON RankedPilotesViewCategorie.IdGame = g.IdGame JOIN Categorie ON RankedPilotesViewCategorie.idCategorieRanked=Categorie.idCategorie
go


CREATE VIEW IsaCategorie AS 
SELECT 
    Categorie.idCategorie AS cat, 
    COUNT(DISTINCT ResultCategorie.IdPilot) AS PilotNumber 

FROM 
    ResultCategorie 
JOIN 
    Categorie ON ResultCategorie.idCategorieRanked = Categorie.idCategorie 
GROUP BY 
    Categorie.idCategorie;


/*calculate poinst based on the number of pilot*/
SELECT Rank ,Name,Categorie,TempsTotal,CASE WHEN Rank<=10 THEN PilotNumber+1-Rank ELSE 0 END AS Points,GameName 
FROM
 ResultCategorie  
JOIN IsaCategorie ON IsaCategorie.cat=ResultCategorie.idCategorieRanked;

/*just give points*/
SELECT Rank ,Name,TempsTotal,Points ,GameName FROM ResultCategorie;


/*******************************/
INSERT INTO Categorie(idCategorie,Categorie) VALUES
	(1,'Pro'),
	(2,'Rookie'),
	(3,'Veteran')
  go

INSERT INTO Pilot (IdPilot, Name, idCategorie)
VALUES
  (1, 'Lewis Hamilton', 1),
  (2, 'Max Verstappen', 1),
  (3, 'Charles Leclerc', 1),
  (4, 'Lando Norris', 2),
  (5, 'Fernando Alonso', 3)
  go


INSERT INTO Race (IdRace, RaceName)
VALUES
  (1, 'Monaco Grand Prix'),
  (2, 'Spanish Grand Prix'),
  (3, 'Canadian Grand Prix'),
  (4, 'French Grand Prix'),
  (5, 'Austrian Grand Prix'),
  (6, 'British Grand Prix')
  go


INSERT INTO Game (IdGame, GameName)
VALUES
  (1, '2024 F1 Championship - Round 1')
  go
  INSERT INTO Game (IdGame, GameName)
VALUES
  (2, '2024 F1 Championship - Round 2')
  go


INSERT INTO Event (IdEvent, IdGame, IdRace, IdPilot, Temps)
VALUES
  (1, 1, 1, 1, '01:08:34'),
  (2, 1, 1, 2, '01:08:42'),
  (3, 1, 1, 3, '01:09:00'),
  (4, 1, 1, 4, '01:10:12'),
  (5, 1, 1, 5, '01:09:23')
  go

  INSERT INTO Event (IdEvent, IdGame, IdRace, IdPilot, Temps)
VALUES
  (6, 1, 2, 1, '01:08:34'),
  (7, 1, 2, 2, '01:08:42'),
  (8, 1, 2, 3, '01:09:00'),
  (9, 1, 2, 4, '01:10:12'),
  (10, 1, 2, 5, '01:09:23')
  go


INSERT INTO Event (IdEvent, IdGame, IdRace, IdPilot, Temps)
VALUES
  (11, 2, 1, 1, '01:08:34'),
  (12, 2, 1, 2, '01:08:42'),
  (13, 2, 1, 3, '01:09:00'),
  (14, 2, 1, 4, '01:10:12'),
  (15, 2, 1, 5, '01:09:23')
  go

  INSERT INTO Event (IdEvent, IdGame, IdRace, IdPilot, Temps)
VALUES
  (16, 2, 2, 1, '01:08:34'),
  (17, 2, 2, 2, '01:08:42'),
  (18, 2, 2, 3, '01:09:00'),
  (19, 2, 2, 4, '01:10:12'),
  (20, 2, 2, 5, '01:09:23')
  go