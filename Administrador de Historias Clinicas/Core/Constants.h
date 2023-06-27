#pragma once

#include <string>

namespace Constants {
//Data Map
	static std::string strUserKey = "Username";
	static std::string strPassKey = "Password";
//Screens Map
	static std::string strLandingForm = "LandingForm";
	static std::string strLoginForm = "LoginForm";
	static std::string strLoginFailedMessage = "LoginFailedMessage";

	static char sqlGetUserLoginData[] = "SELECT Clave FROM Usuarios WHERE Usuario=:1";
	static char sqlGetUserAlias[] = "SELECT Alias FROM Usuarios WHERE Usuario=:1";
	static char sqlGetProfiles[] = "SELECT * FROM PerfilesPsicologicos ORDER BY PerfilID";
	static char sqlGetEntrysForProfile[] = "SELECT * FROM Entradas WHERE PerfilID=:1 ORDER BY Fecha DESC";
	static char sqlGetVolunteer[] = "SELECT * FROM Voluntarios WHERE DNI=:1";
	static char sqlGetEntryDescriptionFromProfileDate[] = "SELECT Entradas.Descripcion FROM Entradas INNER JOIN PerfilesPsicologicos ON Entradas.PerfilID=PerfilesPsicologicos.PerfilID WHERE PerfilesPsicologicos.PerfilID=:1 AND Entradas.Fecha=:2 ";
	static char sqlChangeProfileState[] = "UPDATE PerfilesPsicologicos SET Activa=((Activa | 1) - (Activa & 1)) WHERE PerfilID=:1";
}