#include "PmergeMe.hpp"

int PmergeMe::safeAtoi(const char* str) {
	int result = 0;
	int sign = 1;
	int i = 0;

	// Ignorer les espaces blancs au début de la chaîne
	while (isspace(str[i])) {
		i++;
	}
	// Gérer les signes + ou -
	if (str[i] == '+' || str[i] == '-') {
		if (str[i] == '-') {
			throw PmergeMe::PMMException("not a positive number");
		}
		i++;
	}
	// Vérifier que tous les caractères restants sont des chiffres
	while (isdigit(str[i])) {
		result = result * 10 + (str[i] - '0');
		i++;
	}
	// Si on trouve un caractère non-numérique avant la fin de la chaîne,
	// on retourne 0 pour signaler une erreur.
	if (str[i] != '\0') {
		throw PmergeMe::PMMException("Not a number");
	}
	// Retourner le résultat avec le signe approprié
	return result * sign;
}