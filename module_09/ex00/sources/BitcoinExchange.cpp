/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:41:19 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/05 14:29:49 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

/* CONSTRUCTORS */

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _data = other._data;
    }
    return (*this);
}

// METHODS

/*
    Este método lê os valores do arquivo .csv e os armazena no contêiner `_data`.
    Foi escolhido o contêiner `std::map` para possibilitar uma busca eficiente através de uma estrutura chave-valor,
    onde a chave é a data e o valor é a taxa de câmbio correspondente.
    Se o arquivo não puder ser aberto ou o cabeçalho inicial não corresponder ao esperado, uma exceção será lançada.
    O método ignora espaços ao redor dos campos e valida o formato das linhas,
    assegurando que estejam no formato "data,valor" antes de adicioná-las ao contêiner.
*/

int BitcoinExchange::populatingContainer(std::string csv)
{
    std::ifstream file(csv.c_str());

    if (!file)
    {
        throw std::runtime_error("Error opening file! Try again with a valid data.csv.");
    }

    std::string line;
    std::getline(file, line);
    removeSpaces(line);
    if (line != "date,exchange_rate") {
        throw std::runtime_error("Invalid header! Insert: date,exchange_rate ");
    }

    while (std::getline(file, line))
    {
        size_t separator_pos = line.find(",");
        if (separator_pos == std::string::npos)
            throw std::runtime_error("Invalid line format: " + line);
    
        std::string date = line.substr(0, separator_pos);
        std::string valueStr = line.substr(separator_pos + 1);

        removeSpaces(date);
        removeSpaces(valueStr);

        float exchange_value = stringToFloat(valueStr);
        _data[date] = exchange_value;
    }
    return (0);
}

/*
    Este método lê as entradas do arquivo .txt e verifica se ele contém o cabeçalho esperado: `date | value`.
    Caso o cabeçalho seja válido, o método processa cada linha do arquivo .txt e ignora linhas vazias.
    Cada entrada é então passada para o método `formatData`, que valida e converte o valor 
    para a taxa de câmbio do Bitcoin, garantindo que apenas dados corretamente formatados 
    e validados sejam processados.
*/

void BitcoinExchange::loadingData(std::ifstream &file)
{
    std::string line;

    std::getline(file, line);
    removeSpaces(line);
    if (line != "date | value")
            throw std::runtime_error("Invalid header! Insert: date | value");
    while (std::getline(file, line))
    {   
        if (line.empty())
        continue ;
        formatData(line);
    }
}

/*
   Método principal: fluxo de validação e conversão de dados em .txt.
   Recebe uma linha do arquivo .txt, valida e extrai a data e o valor.
   Se a validação for bem-sucedida, chama o método para converter o valor.
*/

void BitcoinExchange::formatData(const std::string &line)
{
    std::string date;
    float value;

    if (validateAndExtractData(line, date, value)) {
        convertValue(date, value);
    }
}

/*
    Método para validar e extrair valores de .txt.
    Recebe uma linha de entrada, verifica se a linha contém um formato válido (date | value).
    Extrai a data e o valor, removendo espaços em branco.
    Retorna true se a validação for bem-sucedida e as variáveis de saída 'date' e 'value' são preenchidas.
    Caso contrário, imprime mensagens de erro apropriadas e retorna false.
*/

bool BitcoinExchange::validateAndExtractData(const std::string &line, std::string &date, float &value)
{
    std::string trimmed_line = line;
    removeSpaces(trimmed_line);
    size_t separator_pos = trimmed_line.find_first_of("|");

    if (separator_pos == std::string::npos) {
        std::cout << BRIGHT_RED "Error: bad input => " RESET << line << std::endl;
        return false;
    }

    date = trimmed_line.substr(0, separator_pos);
    std::string valueStr = trimmed_line.substr(separator_pos + 1);

    removeSpaces(date);
    removeSpaces(valueStr);

    if (valueStr.empty()) {
        std::cout << BRIGHT_RED "Error: missing value for date => " RESET << date << std::endl;
        return false;
    }

    try {
        validateDate(date);
    } catch (const std::runtime_error &e) {
        std::cout << BRIGHT_RED "Error: invalid date => " RESET << date << std::endl;
        return false;
    }

    try {
        value = validateValue(valueStr);
    } catch (const std::runtime_error &e) {
        std::string errMsg = e.what();
        if (errMsg == "negative")
            std::cout << BRIGHT_RED "Error: not a positive number." RESET << std::endl;
        else if (errMsg == "too large")
            std::cout << BRIGHT_RED "Error: too large a number." RESET << std::endl;
        else if (errMsg == "invalid")
            std::cout << BRIGHT_RED "Error: converting value." << RESET << std::endl;
        return false;
    }

    return true;
}

/*
    Método para converter o valor usando a taxa de câmbio mais próxima disponível.
    Recebe uma data e um valor a ser convertido.
    Procura pela taxa de câmbio correspondente à data ou a mais próxima anterior.
    Se uma taxa for encontrada, calcula e exibe o valor convertido.
    Caso contrário, imprime uma mensagem de erro indicando que a taxa não foi encontrada para a data fornecida.
*/

void BitcoinExchange::convertValue(const std::string &date, float value)
{
    std::map<std::string, float>::iterator closest_it = _data.end();

    for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); ++it) {
        if (it->first == date) {
            closest_it = it;
            break;
        } else if (it->first < date) {
            closest_it = it;
        } else {
            break;
        }
    }

    if (closest_it == _data.end()) {
        std::cout << BRIGHT_RED "Error: exchange rate not found for date => " RESET << date << std::endl;
        return;
    }

    float convertedValue = value * closest_it->second;
    std::cout << date << " => " << value << " = " << convertedValue << std::endl;
}

/* DESTRUCTOR */

BitcoinExchange::~BitcoinExchange() {}
