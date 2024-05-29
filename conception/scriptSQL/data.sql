drop table Course;
drop table Pilote;
drop table Pilote;
drop table Rallye;
drop table Special;
drop view RankedPilotesView 
drop view RankedPilotesViewCategorie
drop view classementGeneral
drop view ResultCategorie



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






INSERT INTO Saison (annee) VALUES (2023);
INSERT INTO Saison (annee) VALUES (2024);


INSERT INTO Categorie (intituler) VALUES ('A');
INSERT INTO Categorie (intituler) VALUES ('B');
INSERT INTO Categorie (intituler) VALUES ('C');


INSERT INTO pilote (nompilote, idCategorie,intitulerCategorie ) VALUES ('John', 1,'A');
INSERT INTO pilote (nompilote, idCategorie,intitulerCategorie ) VALUES ('Emma', 2,'B');
INSERT INTO pilote (nompilote, idCategorie,intitulerCategorie ) VALUES ('Michael', 3,'C');
INSERT INTO pilote (nompilote, idCategorie,intitulerCategorie ) VALUES ('Sophia', 1,'A');
INSERT INTO pilote (nompilote, idCategorie,intitulerCategorie ) VALUES ('William', 2,'B');

INSERT INTO Rallye (intituler) VALUES ('Rallye Monte Carlo');
INSERT INTO Rallye (intituler) VALUES ('Rallye Dakar');
INSERT INTO Rallye (intituler) VALUES ('Rallye Finlande');







INSERT INTO Special (intituler) VALUES ('Special 1');
INSERT INTO Special (intituler) VALUES ('Special 2');
INSERT INTO Special (intituler) VALUES ('Special 3');


INSERT INTO Course (idRallye, idSpecial, idPilote, chronometre) VALUES 
(1, 1, 1, '00:02:30'), (1, 1, 2, '00:02:45'), (1, 1, 3, '00:02:20'), (1, 1, 4, '00:02:35'), (1, 1, 5, '00:02:25'),
(1, 2, 1, '00:03:10'), (1, 2, 2, '00:03:05'), (1, 2, 3, '00:03:15'), (1, 2, 4, '00:03:00'), (1, 2, 5, '00:03:20'),
(1, 3, 1, '00:01:50'), (1, 3, 2, '00:01:45'), (1, 3, 3, '00:01:55'), (1, 3, 4, '00:02:00'), (1, 3, 5, '00:01:40');


INSERT INTO Course (idRallye, idSpecial, idPilote, chronometre) VALUES 
(2, 1, 1, '00:02:25'), (2, 1, 2, '00:02:30'), (2, 1, 3, '00:02:20'), (2, 1, 4, '00:02:35'), (2, 1, 5, '00:02:40'),
(2, 2, 1, '00:03:15'), (2, 2, 2, '00:03:20'), (2, 2, 3, '00:03:10'), (2, 2, 4, '00:03:05'), (2, 2, 5, '00:03:25'),
(2, 3, 1, '00:01:40'), (2, 3, 2, '00:01:45'), (2, 3, 3, '00:01:35'), (2, 3, 4, '00:01:50'), (2, 3, 5, '00:01:55');


INSERT INTO Course (idRallye, idSpecial, idPilote, chronometre) VALUES 
(3, 1, 1, '00:02:20'), (3, 1, 2, '00:02:25'), (3, 1, 3, '00:02:15'), (3, 1, 4, '00:02:30'), (3, 1, 5, '00:02:35'),
(3, 2, 1, '00:03:00'), (3, 2, 2, '00:03:05'), (3, 2, 3, '00:02:55'), (3, 2, 4, '00:03:10'), (3, 2, 5, '00:03:15'),
(3, 3, 1, '00:01:30'), (3, 3, 2, '00:01:35'), (3, 3, 3, '00:01:25'), (3, 3, 4, '00:01:40'), (3, 3, 5, '00:01:45');
