USE Soles_DB

CREATE TABLE Usuarios(
    UsuarioID int,
    Usuario varchar(255),
    Clave BIGINT
)

CREATE TABLE Voluntarios(
    DNI varchar(255),
    Usuario varchar(255),
    Contrasena varchar(255)
)

CREATE TABLE Historias(
    ID int,
    VoluntarioDNI varchar(255)
)

CREATE TABLE HistoriasEntradas(
	HistoriaID int,
	EntradaID int
)

CREATE TABLE Entradas(
	EntradaID int,
    Fecha date,
    Descripcion varchar(1000),
    UsuarioID int
)