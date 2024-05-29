sqlCREATE DATABASE rallye_project

CREATE TABLE Categorie (
    idCategorie INT PRIMARY KEY IDENTITY(1,1),
    intituler VARCHAR(50)
);

CREATE TABLE Pilote (
    idPilote INT PRIMARY KEY IDENTITY(1,1),
    nomPilote VARCHAR(50),
    idCategorie INT FOREIGN KEY REFERENCES Categorie(idCategorie),
    intitulerCategorie VARCHAR(50)
);

CREATE TABLE Saison (
    idSaison INT PRIMARY KEY IDENTITY(1,1),
    annee INT
);


CREATE TABLE Rallye (
    idRallye INT PRIMARY KEY IDENTITY(1,1),
    intituler VARCHAR(50)
);

CREATE TABLE Special (
    idSpecial INT PRIMARY KEY IDENTITY(1,1),
    intituler VARCHAR(50),
);

CREATE TABLE Course (
    idCourse INT PRIMARY KEY IDENTITY(1,1),
    idSaison INT  FOREIGN KEY REFERENCES Saison(idSaison), 
    idRallye INT FOREIGN KEY REFERENCES Rallye(idRallye),
    idSpecial INT FOREIGN KEY REFERENCES Special(idSpecial),
    idPilote INT FOREIGN KEY REFERENCES Pilote(idPilote),
    chronometre TIME
);

INSERT INTO Pilote (nomPilote, idCategorie,intituler)
VALUES
  ('Lewis Hamilton', 1,'Pro'),
  ('Max Verstappen', 1,'Pro'),
  ('Charles Leclerc', 1,'Pro'),
  ('Lando Norris', 2,'Rookie'),
  ('Fernando Alonso', 3,'Veteran')




INSERT INTO Special(intituler)
VALUES
  ('Monaco Grand Prix'),
  ('Spanish Grand Prix'),
  ('Canadian Grand Prix'),
  ('French Grand Prix'),
  ('Austrian Grand Prix'),
  ('British Grand Prix')


INSERT INTO Rallye (intituler)
VALUES
  ('2024 F1 Championship - Round 1')
  INSERT INTO Game (IdGame, GameName)
VALUES
  ('2024 F1 Championship - Round 2')
 


INSERT INTO Course (idRallye,idSpecial,idPilote,chronometre)
VALUES
  (1, 1, 1, '01:08:34'),
  (1, 1, 2, '01:08:42'),
  (1, 1, 3, '01:09:00'),
  (1, 1, 4, '01:10:12'),
  (1, 1, 5, '01:09:23')
  

INSERT INTO Course (idRallye,idSpecial,idPilote,chronometre)
VALUES
  (1, 2, 1, '01:08:34'),
  (1, 2, 2, '01:08:42'),
  (1, 2, 3, '01:09:00'),
  (1, 2, 4, '01:10:12'),
  (1, 2, 5, '01:09:23')
  


INSERT INTO Course (idRallye,idSpecial,idPilote,chronometre)
VALUES
  (2, 1, 1, '01:08:34'),
  (2, 1, 2, '01:08:42'),
  (2, 1, 3, '01:09:00'),
  (2, 1, 4, '01:10:12'),
  (2, 1, 5, '01:09:23')
  go

  INSERT INTO Course (idRallye,idSpecial,idPilote,chronometre)
VALUES
  (2, 2, 1, '01:08:34'),
  (2, 2, 2, '01:08:42'),
  (2, 2, 3, '01:09:00'),
  (2, 2, 4, '01:10:12'),
  (2, 2, 5, '01:09:23')