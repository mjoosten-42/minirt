/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   log.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 15:31:06 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/21 17:58:25 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# define ANSI_RED "\x1b[31m"
# define ANSI_RESET "\x1b[0m"

# define LOG(a) log_msg(__LINE__, __FILE__, __func__, a)
# define LOG_ERR(a) log_err(__LINE__, __FILE__, __func__, a)

void	log_msg(int line, const char *file, const char *func, const char *msg);
void	log_err(int line, const char *file, const char *func, const char *msg);

#endif
