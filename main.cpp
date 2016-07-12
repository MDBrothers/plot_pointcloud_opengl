# include "write.hpp"
#include "plot3d.hpp"
#include <cmath>

inline double distance(const double x, const double z, const double x_c, const double z_c){
  return sqrt( (x-x_c)*(x-x_c)  +  (z-z_c)*(z-z_c) );
}

inline bool is_in_cylinder(const double x, const double z, const double x_c, const double z_c, const double radius){
  return ( distance(x,z,x_c,z_c) < radius );
}

inline bool is_in_rectangle(const double x, const double z, const double x_c, const double z_c, const double h_x, const double h_z){
  return ( ( abs(x - x_c) < h_x ) and ( abs(z - z_c) < h_z ) );
}

// inline bool is_in_ellipse(const double x, const double z, const double x_c, const double z_c, const double a_x, const double b_z){
//   return ( x)
// }

int main(){
  std::vector<float> vertices, colors, vertices_blocks_volumes;
  std::vector<double> xmax, xmin, ymax;
  //std::vector<std::string> labels;
  //labels.push_back("# X_coord, Y_coord, Z_coord, block_number, volume");
  //writeCSVContents<std::string>("mesh.txt", labels, 1);

  double x_width(100.0), y_width(100.0), z_width(100.0), grid_spacing(.5), fillet_rad(z_width/4.0);
  double block_one_lower(9.0), block_two_lower(1.0);
  double volume(grid_spacing*grid_spacing*grid_spacing);

  unsigned num_x( unsigned( ceil(x_width/grid_spacing) ) ),
          num_y( unsigned( ceil(y_width/grid_spacing) ) ),
          num_z( unsigned( ceil(z_width/grid_spacing) ) );

  unsigned nodenum(0);

  for(unsigned x_index = 0; x_index < num_x; x_index++){
    for(unsigned y_index = 0; y_index < num_y; y_index++){
      for(unsigned z_index = 0; z_index < num_z; z_index++){
        double x(double(x_index)*grid_spacing),
              y(double(y_index)*grid_spacing),
              z(double(z_index)*grid_spacing);

        // if(not (is_in_cylinder(x, z, x_width/4.0, 0.0, fillet_rad) ) ){
        //   if(not (is_in_cylinder(x, z, x_width - x_width/4.0, 0.0, fillet_rad) ) ){
        //     if(not (is_in_cylinder(x, z, x_width/4.0, z_width, fillet_rad) ) ){
        //       if(not (is_in_cylinder(x, z, x_width - x_width/4.0, z_width, fillet_rad) ) ){
        //         if(not (is_in_rectangle(x, z, x_width/2.0, 0.0, x_width/4.0, fillet_rad) ) ){
        //           if(not (is_in_rectangle(x, z, x_width/2.0, z_width, x_width/4.0, fillet_rad) ) ){

                    vertices.push_back( float(x) );
                    vertices.push_back(  float(y) );
                    vertices.push_back(  float(z) );

                    vertices_blocks_volumes.push_back(  float(x) );
                    vertices_blocks_volumes.push_back( float(y) );
                    vertices_blocks_volumes.push_back(  float(z) );
                    vertices_blocks_volumes.push_back(  float(1.0));


                    vertices_blocks_volumes.push_back(  float(1.0) );
        //           }
        //         }
        //       }
        //     }
        //   }
        // }

      }
    }
  }

  //writeCSVContents<double>("mesh.txt", vertices_blocks_volumes, 5);
  // writeCSVContents<double>("max_x_nodes.txt", xmax, 1);
  // writeCSVContents<double>("min_x_nodes.txt", xmin, 1);
  // writeCSVContents<double>("max_y_nodes.txt", ymax, 1);


  plotCurve(vertices);

  return 0;
}
