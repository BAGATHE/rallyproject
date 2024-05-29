
/*classement general par temps*/
CREATE  VIEW RankedPilotesView AS
SELECT course.idRallye, 
       p.nomPilote,
       p.idPilote, 
       p.idCategorie as idCategorieRanked,
       p.intitulerCategorie as categorie,
       SUM(course.chronometre) AS TempsTotal,
       DENSE_RANK() OVER (PARTITION BY course.idRallye ORDER SUM(course.chronometre) ASC) AS Rank
FROM Course course
JOIN Pilote p ON course.idPilote = p.idPilote
GROUP BY course.idRallye, p.idPilote, p.nomPilote, p.idCategorie,p.intitulerCategorie ;


/*I- General result*/
CREATE VIEW v_classementGeneral AS  
SELECT rallye.idRallye,
       RankedPilotesView.idPilote,
       rallye.intituler as rallyeName,
       nomPilote,
       Categorie.intituler as Categorie,
       TempsTotal,
       Rank,
       CASE
         WHEN Rank = 1 THEN 10
         WHEN Rank = 2 THEN 9
         WHEN Rank = 3 THEN 8
         WHEN Rank = 4 THEN 7
         WHEN Rank = 5 THEN 6
         WHEN Rank = 6 THEN 5
         WHEN Rank = 7 THEN 4
         WHEN Rank = 8 THEN 3
         WHEN Rank = 9 THEN 2
         WHEN Rank = 10 THEN 1
         ELSE 0
       END AS Points
FROM RankedPilotesView 
LEFT JOIN Rallye rallye ON RankedPilotesView.idRallye = rallye.idRallye 
JOIN Categorie ON RankedPilotesView.idCategorieRanked = Categorie.idCategorie;





/**classement par categorie**/
CREATE OR REPLACE VIEW RankedPilotesViewCategorie AS
SELECT course.idRallye, 
       p.nomPilote,
       p.idPilote, 
       p.idCategorie as idCategorieRanked, 
       p.intitulerCategorie as categorie,
       CONVERT(TIME, DATEADD(SECOND, SUM(DATEDIFF(SECOND, '00:00:00', course.chronometre)), '00:00:00')) AS TempsTotal,
       DENSE_RANK() OVER (PARTITION BY course.idRallye, p.idCategorie ORDER BY CONVERT(TIME, DATEADD(SECOND, SUM(DATEDIFF(SECOND, '00:00:00', course.chronometre)), '00:00:00')) ASC) AS Rank
FROM Course course
JOIN Pilote p ON course.idPilote = p.idPilote
GROUP BY course.idRallye, p.idPilote, p.nomPilote, p.idCategorie, p.intitulerCategorie;







/***CLASSEMENT PAR CATEGORIE***/
CREATE VIEW ResultCategorie AS  SELECT rallye.idRallye,RankedPilotesViewCategorie.idCategorieRanked,RankedPilotesViewCategorie.idPilote, rallye.intituler as GameName, nomPilote, Categorie.intituler as Categorie, TempsTotal, Rank,
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
FROM RankedPilotesViewCategorie LEFT JOIN Rallye rallye ON RankedPilotesViewCategorie.idRallye = rallye.idRallye JOIN Categorie ON RankedPilotesViewCategorie.idCategorieRanked=Categorie.idCategorie




