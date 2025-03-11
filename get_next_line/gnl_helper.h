/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_helper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:37:54 by dthan             #+#    #+#             */
/*   Updated: 2025/03/11 16:58:42 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_HELPER_H
# define GNL_HELPER_H

int	valid_fd(int fd);
int	get_line_break_index(char *s);
int	extract_line_from_storage(char **storage, char **line);

#endif
