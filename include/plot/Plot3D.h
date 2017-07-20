/**
 * \author Alexander Entinger
 */

#ifndef SRC_PLOT3D_H_
#define SRC_PLOT3D_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <plot/PlotBase.h>

#include <vector>

#include <boost/tuple/tuple.hpp>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class Plot3D : public PlotBase
{

public:

  /**************************************************************************************
   * Plot3D::DataPoint
   **************************************************************************************/

  class DataPoint
  {
  public:

    double x;
    double y;
    double z;

    DataPoint(double const x, double const y, double const z);
  };

  /**************************************************************************************
   * Plot3D::SingleGraphData
   **************************************************************************************/

  typedef std::vector<DataPoint> DataPointVect;

  class SingleGraphData
  {
  public:

    SingleGraphData(std::string const & title, std::string const & point_type, DataPointVect const & data_point_vect);

    inline std::string    title           () const { return this->_title;           }
    inline std::string    point_type      () const { return this->_point_type;      }
    inline DataPointVect  data_point_vect () const { return this->_data_point_vect; }

  private:

    std::string   _title;
    std::string   _point_type;
    DataPointVect _data_point_vect;

  };

  /**************************************************************************************
   * Plot3D
   **************************************************************************************/

   Plot3D(std::string     const & window_title,
          std::string     const & plot_title,
          std::string     const & x_label,
          std::string     const & y_label,
          std::string     const & z_label,
          std::string     const & x_range,
          std::string     const & y_range,
          std::string     const & z_range,
          SingleGraphData const & data);
  ~Plot3D();

private:

  typedef std::vector<boost::tuple<double, double, double> > GnuplotDataVect;

  void            plot                    (SingleGraphData const & data);
  GnuplotDataVect convertToGnuplotDataVect(DataPointVect   const & data) const;

};

#endif /* SRC_PLOT3D_H_ */
