/**
 * @file thdb1d.h
 * 2D data structure processing class.
 */
  
/* Copyright (C) 2000 Stacho Mudrak
 * 
 * $Date: $
 * $RCSfile: $
 * $Revision: $
 *
 * -------------------------------------------------------------------- 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * --------------------------------------------------------------------
 */
 
#ifndef thdb2d_h
#define thdb2d_h

#include "thinfnan.h"
#include "thdb2dprj.h"
#include "thmbuffer.h"
#include "thbuffer.h"
#include "thdb2dpt.h"
#include "thdb2dlp.h"
#include "thdb2dab.h"
#include "thdb2dji.h"
#include "thdb2dmi.h"
#include "thdb2dcp.h"
#include "thdb2dxs.h"
#include "thdb2dxm.h"
#include "thscraplo.h"
#include "thlayoutln.h"
#include "thscrapen.h"
#include "thscraplp.h"
#include <stdio.h>




/**
 * Projection ID structure. */
 
class thdb2dprjpr {
  
  public:
  
  thdb2dprj * prj;  ///< Projection parameters.
  bool newprj,  ///< Whether projection is new.
    parok;  ///< Whether parameters are OK.
    
  thdb2dprjpr() : prj(NULL), newprj(false), parok(false) {}
    
};


/**
 * 2D data structure processing class.
 */
 
class thdb2d {

  public:
  
  class thdatabase * db;  ///< Our database.
  thdb2dprj_list prj_list;  ///< Set of projections.
  thdb2dprjid_map prjid_map;
  int prj_lid;  ///< Last projection id.
  thdb2dprj * prj_default;  ///< Default projection.
  
  thdb2dpt_list pt_list;  ///< List of 2D points.
  thdb2dlp_list lp_list;  ///< List of path points.
  thdb2dab_list ab_list;  ///< List of area border lines.
  thdb2dji_list ji_list;  ///< List of join items.
  thdb2dmi_list mi_list;  ///< List of map items.
  thdb2dcp_list cp_list;  ///< Control point list.
  thdb2dxm_list xm_list;  ///< Export map list.
  thdb2dxs_list xs_list;  ///< Export scrap list.
  thscraplo_list scraplo_list;  ///< Export map list.
  thscrapen_list scrapen_list;  ///< Export map list.
  thlayoutln_list layoutln_list;  ///< Export map list.
  thscraplp_list scraplp_list;  ///< Export scrap list.
  
  void process_area_references(class tharea * aptr);  ///< ???
  void process_point_references(class thpoint * pp);  ///< ???
  void process_map_references(class thmap * mptr);  ///< ???
  void postprocess_map_references(class thmap * mptr);  ///< ???
  void process_join_references(class thjoin * jptr);  ///< ???
  void process_scrap_references(class thscrap * sptr);  ///< ???

  void pp_find_scraps_and_joins(thdb2dprj * prj); ///< ???
  void pp_scale_points(thdb2dprj * prj);  ///< ???
  void pp_calc_limits(thdb2dprj * prj);  ///< ???
  void pp_calc_stations(thdb2dprj * prj);  ///< ???
  void pp_adjust_points(thdb2dprj * prj);  ///< ???
  void pp_shift_points(thdb2dprj * prj, bool calc_az = false);  ///< ???
  void pp_process_joins(thdb2dprj * prj); ///< ???
  void pp_smooth_lines(thdb2dprj * prj);  ///< ???
  void pp_smooth_joins(thdb2dprj * prj);  ///< ???

  void insert_basic_maps(thdb2dxm * fmap, thmap * map, int mode, int level); ///< ???
  thdb2dxm * insert_maps(thdb2dxm * selection,thdb2dxm * insert_after,thmap * map, 
    unsigned long selection_level, int level, int title_level, int map_level); ///< ???
  void reset_selection();
    
  public:

  thmbuffer mbf,  ///< Multi buffer.
    mbf2; ///< Second buffer.
  thbuffer bf; /// Buffer.
    
  /**
   * Standard constructor.
   */
  
  thdb2d();
  
  
  /**
   * Destructor.
   */
  
  ~thdb2d();
  
  
  /*
   * Assign database pointer.
   */
   
  void assigndb(thdatabase * dbptr);
  

  /**
   * Print self.
   */
   
  void self_print(FILE * outf);
  
  
  /**
   * Parse projection.
   *
   * Return projection identifier - if projection found or newly created -
   * or negative number, if parameters are not consistent.
   */
   
  thdb2dprjpr parse_projection(char * prjstr,bool insnew = true);
  
  
  /**
   * Insert 2D point.
   */
   
  thdb2dpt * insert_point();
  
  
  /**
   * Insert 2D line point.
   */
   
  thdb2dlp * insert_line_point();
  
  
  /**
   * Insert area border line.
   */
  
  thdb2dab * insert_border_line();
  
  
  /**
   * Insert join item.
   */
  
  thdb2dji * insert_join_item();
  
  
  /**
   * Insert map item.
   */
  
  thdb2dmi * insert_map_item();
  
  
  /**
   * Insert control point.
   */
  
  thdb2dcp * insert_control_point();
  
  
  /**
   * Insert export scrap.
   */
   
  thdb2dxs * insert_xs();


  /**
   * Insert export map.
   */
   
  thdb2dxm * insert_xm();
  
   
  /**
   * Insert ...
   */
   
  thscraplo * insert_scraplo();
  
  
  /**
   * Insert ...
   */
   
  thlayoutln * insert_layoutln();
  
  
  /**
   * Insert ...
   */
   
  thscrapen * insert_scrapen();
  
  
  /**
   * Insert ...
   */
   
  thscraplp * insert_scraplp();
  
  
  /**
   * Process 2D references.
   */
   
  void process_references();
  
  
  /**
   * Return efault projection.
   */
   
  thdb2dprj * get_default_projection() {return this->prj_default;}
  
  
  /**
   * Process projection.
   */
   
  void process_projection(thdb2dprj * prj);
  
  
  /**
   * Make map selection.
   */
   
  thdb2dxm * select_projection(thdb2dprj * prj);
  
  
  /**
   * Get projection title.
   */
   
  char * get_projection_title(thdb2dprj * prj);
  
};


#endif


