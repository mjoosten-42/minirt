/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:20:53 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/16 11:34:31 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

typedef enum e_object_type
{
	OBJECT_NONE,
	OBJECT_CAMERA,
	OBJECT_LIGHT,
	OBJECT_AMBIENCE,
	OBJECT_SPHERE,
	OBJECT_PLANE,
	OBJECT_CYLINDER,
	OBJECT_CONE
}	t_object_type;

#endif