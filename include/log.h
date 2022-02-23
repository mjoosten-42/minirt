/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   log.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 15:31:06 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/23 10:55:34 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

/*
**	My not-so-norm easy log system
**	LOG(message) for a nice log message
**	LOG_ERR(message) for a nice RED log message
*/

# define ANSI_RED "\x1b[31m"
# define ANSI_RESET "\x1b[0m"

/**
**	NOT NORM way to print log message with file:line & function to STDOUT
**	@param a Custom message to print
*/
# define LOG(a) log_msg(__LINE__, __FILE__, __func__, a)

/**
**	NOT NORM way to print log message with file:line & function to STDOUT. 
**	Printed text is simply RED for clarity
**	@param a Custom message to print
*/
# define LOG_ERR(a) log_err(__LINE__, __FILE__, __func__, a)

void	log_msg(int line, const char *file, const char *func, const char *msg);
void	log_err(int line, const char *file, const char *func, const char *msg);

#endif
