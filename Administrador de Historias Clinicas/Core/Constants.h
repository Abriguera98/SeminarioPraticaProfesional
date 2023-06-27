#pragma once

#include <string>

namespace Constants {
//Data Map
	static std::string strUserKey = "Username";
	static std::string strPassKey = "Password";
//SQL Procedures
	static char sqlGetUserLoginData[] = "SELECT Clave FROM Usuarios WHERE Usuario=:1";
	static char sqlGetUserAlias[] = "SELECT Alias, UsuarioID FROM Usuarios WHERE Usuario=:1";
	static char sqlGetProfiles[] = "SELECT * FROM PerfilesPsicologicos ORDER BY PerfilID";
	static char sqlGetEntrysForProfile[] = "SELECT * FROM Entradas WHERE PerfilID=:1 ORDER BY Fecha DESC";
	static char sqlGetVolunteer[] = "SELECT * FROM Voluntarios WHERE DNI=:1";
	static char sqlGetEntryDescriptionFromProfileDate[] = "SELECT Entradas.Descripcion FROM Entradas INNER JOIN PerfilesPsicologicos ON Entradas.PerfilID=PerfilesPsicologicos.PerfilID WHERE PerfilesPsicologicos.PerfilID=:1 AND Entradas.Fecha=:2 ";
	static char sqlGetEntryAuthorFromProfileDate[] = "SELECT Usuarios.Alias FROM Usuarios INNER JOIN Entradas ON Usuarios.UsuarioID=Entradas.UsuarioID INNER JOIN PerfilesPsicologicos ON Entradas.PerfilID=PerfilesPsicologicos.PerfilID WHERE PerfilesPsicologicos.PerfilID=:1 AND Entradas.Fecha=:2;";
	static char sqlChangeProfileState[] = "UPDATE PerfilesPsicologicos SET Activa=((Activa | 1) - (Activa & 1)) WHERE PerfilID=:1";
	static char sqlCreateNewEmptyProfile[] = "INSERT INTO Voluntarios (DNI, Nombre, Apellido) VALUES (:3, :1, :2); INSERT INTO PerfilesPsicologicos (VoluntarioDNI, Activa) VALUES (:3 , 1)";
	static char sqlGetUserFullData[] = "SELECT * FROM Usuarios WHERE Usuario=:1";
	static char sqlInsertEntry[] = "INSERT INTO Entradas (Fecha, Descripcion, UsuarioID, PerfilID) VALUES (:1, :2, :3, :4)";
}