/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:23:44 by daekim            #+#    #+#             */
/*   Updated: 2021/03/16 06:42:40 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		info2(t_info *p)
{
	p->hurt = 0;
	p->hp = 5;
	p->key_p = 0;
	p->mou_u = 0;
	p->mou_d = 0;
	p->mou_r = 0;
	p->mou_l = 0;
	p->mou_ud = 0;
	p->mou_lr = 0;
	p->key_jump = 0;
	p->sp.v_move = 0.0;
	p->sp.sp_flag = 0;
	p->level_up = 0;
}

void		info(t_info *p)
{
	p->move = 0.05;
	p->rot = 0.05;
	p->key_w = 0;
	p->key_s = 0;
	p->key_d = 0;
	p->key_a = 0;
	p->key_e = 0;
	p->key_q = 0;
	p->key_al = 0;
	p->key_ar = 0;
	p->key_ws = 0;
	p->key_ad = 0;
	p->key_qe = 0;
	p->key_aa = 0;
	p->key_sit = 0;
	p->key_up = 0;
	p->key_down = 0;
	p->key_ud = 0;
	p->sp_count = 0;
	p->is_save = 0;
	p->cal.f_rgb = 0;
	p->cal.c_rgb = 0;
	p->pitch = 0;
	info2(p);
}
