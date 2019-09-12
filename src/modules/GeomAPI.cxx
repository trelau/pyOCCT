/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Curve.hxx>
#include <gp_Pln.hxx>
#include <GeomAPI_ProjectPointOnCurve.hxx>
#include <GeomAPI_ProjectPointOnSurf.hxx>
#include <GeomAPI_ExtremaCurveCurve.hxx>
#include <GeomAPI_ExtremaCurveSurface.hxx>
#include <GeomAPI_ExtremaSurfaceSurface.hxx>
#include <GeomAPI_PointsToBSpline.hxx>
#include <GeomAPI_PointsToBSplineSurface.hxx>
#include <GeomAPI_Interpolate.hxx>
#include <GeomAPI_IntSS.hxx>
#include <GeomAPI_IntCS.hxx>
#include <GeomAPI.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Extrema_ExtCC.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <Geom_Surface.hxx>
#include <Extrema_ExtCS.hxx>
#include <Extrema_ExtSS.hxx>
#include <IntCurveSurface_HInter.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <gp_Vec.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColStd_HArray1OfBoolean.hxx>
#include <Geom_BSplineCurve.hxx>
#include <TColgp_HArray1OfVec.hxx>
#include <GeomInt_IntSS.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <GeomAbs_Shape.hxx>
#include <Approx_ParametrizationType.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Extrema_ExtPC.hxx>
#include <Extrema_ExtAlgo.hxx>
#include <Extrema_ExtFlag.hxx>
#include <Extrema_ExtPS.hxx>
#include <GeomAdaptor_Surface.hxx>

PYBIND11_MODULE(GeomAPI, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Geom");
py::module::import("OCCT.gp");
py::module::import("OCCT.Extrema");
py::module::import("OCCT.GeomAdaptor");
py::module::import("OCCT.IntCurveSurface");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.GeomInt");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Approx");

// CLASS: GEOMAPI
py::class_<GeomAPI> cls_GeomAPI(mod, "GeomAPI", "The GeomAPI package provides an Application Programming Interface for the Geometry.");

// Methods
// cls_GeomAPI.def_static("operator new_", (void * (*)(size_t)) &GeomAPI::operator new, "None", py::arg("theSize"));
// cls_GeomAPI.def_static("operator delete_", (void (*)(void *)) &GeomAPI::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI.def_static("To2d_", (opencascade::handle<Geom2d_Curve> (*)(const opencascade::handle<Geom_Curve> &, const gp_Pln &)) &GeomAPI::To2d, "This function builds (in the parametric space of the plane P) a 2D curve equivalent to the 3D curve C. The 3D curve C is considered to be located in the plane P. Warning The 3D curve C must be of one of the following types: - a line - a circle - an ellipse - a hyperbola - a parabola - a Bezier curve - a BSpline curve Exceptions Standard_NoSuchObject if C is not a defined type curve.", py::arg("C"), py::arg("P"));
cls_GeomAPI.def_static("To3d_", (opencascade::handle<Geom_Curve> (*)(const opencascade::handle<Geom2d_Curve> &, const gp_Pln &)) &GeomAPI::To3d, "Builds a 3D curve equivalent to the 2D curve C described in the parametric space defined by the local coordinate system of plane P. The resulting 3D curve is of the same nature as that of the curve C.", py::arg("C"), py::arg("P"));

// CLASS: GEOMAPI_EXTREMACURVECURVE
py::class_<GeomAPI_ExtremaCurveCurve> cls_GeomAPI_ExtremaCurveCurve(mod, "GeomAPI_ExtremaCurveCurve", "Describes functions for computing all the extrema between two 3D curves. An ExtremaCurveCurve algorithm minimizes or maximizes the distance between a point on the first curve and a point on the second curve. Thus, it computes start and end points of perpendiculars common to the two curves (an intersection point is not an extremum unless the two curves are tangential at this point). Solutions consist of pairs of points, and an extremum is considered to be a segment joining the two points of a solution. An ExtremaCurveCurve object provides a framework for: - defining the construction of the extrema, - implementing the construction algorithm, and - consulting the results. Warning In some cases, the nearest points between two curves do not correspond to one of the computed extrema. Instead, they may be given by: - a limit point of one curve and one of the following: - its orthogonal projection on the other curve, - a limit point of the other curve; or - an intersection point between the two curves.");

// Constructors
cls_GeomAPI_ExtremaCurveCurve.def(py::init<>());
cls_GeomAPI_ExtremaCurveCurve.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &>(), py::arg("C1"), py::arg("C2"));
cls_GeomAPI_ExtremaCurveCurve.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U1min"), py::arg("U1max"), py::arg("U2min"), py::arg("U2max"));

// Methods
// cls_GeomAPI_ExtremaCurveCurve.def_static("operator new_", (void * (*)(size_t)) &GeomAPI_ExtremaCurveCurve::operator new, "None", py::arg("theSize"));
// cls_GeomAPI_ExtremaCurveCurve.def_static("operator delete_", (void (*)(void *)) &GeomAPI_ExtremaCurveCurve::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI_ExtremaCurveCurve.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI_ExtremaCurveCurve::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI_ExtremaCurveCurve.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI_ExtremaCurveCurve::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI_ExtremaCurveCurve.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI_ExtremaCurveCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI_ExtremaCurveCurve.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI_ExtremaCurveCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI_ExtremaCurveCurve.def("Init", (void (GeomAPI_ExtremaCurveCurve::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &)) &GeomAPI_ExtremaCurveCurve::Init, "Initializes this algorithm with the given arguments and computes the extrema between the curves C1 and C2", py::arg("C1"), py::arg("C2"));
cls_GeomAPI_ExtremaCurveCurve.def("Init", (void (GeomAPI_ExtremaCurveCurve::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomAPI_ExtremaCurveCurve::Init, "Initializes this algorithm with the given arguments and computes the extrema between : - the portion of the curve C1 limited by the two points of parameter (U1min,U1max), and - the portion of the curve C2 limited by the two points of parameter (U2min,U2max). Warning Use the function NbExtrema to obtain the number of solutions. If this algorithm fails, NbExtrema returns 0.", py::arg("C1"), py::arg("C2"), py::arg("U1min"), py::arg("U1max"), py::arg("U2min"), py::arg("U2max"));
cls_GeomAPI_ExtremaCurveCurve.def("NbExtrema", (Standard_Integer (GeomAPI_ExtremaCurveCurve::*)() const) &GeomAPI_ExtremaCurveCurve::NbExtrema, "Returns the number of extrema computed by this algorithm. Note: if this algorithm fails, NbExtrema returns 0.");
cls_GeomAPI_ExtremaCurveCurve.def("Points", (void (GeomAPI_ExtremaCurveCurve::*)(const Standard_Integer, gp_Pnt &, gp_Pnt &) const) &GeomAPI_ExtremaCurveCurve::Points, "Returns the points P1 on the first curve and P2 on the second curve, which are the ends of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"), py::arg("P1"), py::arg("P2"));
cls_GeomAPI_ExtremaCurveCurve.def("Parameters", [](GeomAPI_ExtremaCurveCurve &self, const Standard_Integer Index, Standard_Real & U1, Standard_Real & U2){ self.Parameters(Index, U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "Returns the parameters U1 of the point on the first curve and U2 of the point on the second curve, which are the ends of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"), py::arg("U1"), py::arg("U2"));
cls_GeomAPI_ExtremaCurveCurve.def("Distance", (Standard_Real (GeomAPI_ExtremaCurveCurve::*)(const Standard_Integer) const) &GeomAPI_ExtremaCurveCurve::Distance, "Computes the distance between the end points of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"));
cls_GeomAPI_ExtremaCurveCurve.def("NearestPoints", (void (GeomAPI_ExtremaCurveCurve::*)(gp_Pnt &, gp_Pnt &) const) &GeomAPI_ExtremaCurveCurve::NearestPoints, "Returns the points P1 on the first curve and P2 on the second curve, which are the ends of the shortest extremum computed by this algorithm. Exceptions StdFail_NotDone if this algorithm fails.", py::arg("P1"), py::arg("P2"));
cls_GeomAPI_ExtremaCurveCurve.def("LowerDistanceParameters", [](GeomAPI_ExtremaCurveCurve &self, Standard_Real & U1, Standard_Real & U2){ self.LowerDistanceParameters(U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "Returns the parameters U1 of the point on the first curve and U2 of the point on the second curve, which are the ends of the shortest extremum computed by this algorithm. Exceptions StdFail_NotDone if this algorithm fails.", py::arg("U1"), py::arg("U2"));
cls_GeomAPI_ExtremaCurveCurve.def("LowerDistance", (Standard_Real (GeomAPI_ExtremaCurveCurve::*)() const) &GeomAPI_ExtremaCurveCurve::LowerDistance, "Computes the distance between the end points of the shortest extremum computed by this algorithm. Exceptions StdFail_NotDone if this algorithm fails.");
cls_GeomAPI_ExtremaCurveCurve.def("Extrema", (const Extrema_ExtCC & (GeomAPI_ExtremaCurveCurve::*)() const) &GeomAPI_ExtremaCurveCurve::Extrema, "return the algorithmic object from Extrema");
cls_GeomAPI_ExtremaCurveCurve.def("TotalNearestPoints", (Standard_Boolean (GeomAPI_ExtremaCurveCurve::*)(gp_Pnt &, gp_Pnt &)) &GeomAPI_ExtremaCurveCurve::TotalNearestPoints, "set in <P1> and <P2> the couple solution points such a the distance [P1,P2] is the minimum. taking in account extremity points of curves.", py::arg("P1"), py::arg("P2"));
cls_GeomAPI_ExtremaCurveCurve.def("TotalLowerDistanceParameters", [](GeomAPI_ExtremaCurveCurve &self, Standard_Real & U1, Standard_Real & U2){ Standard_Boolean rv = self.TotalLowerDistanceParameters(U1, U2); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, U1, U2); }, "set in <U1> and <U2> the parameters of the couple solution points which represents the total nearest solution.", py::arg("U1"), py::arg("U2"));
cls_GeomAPI_ExtremaCurveCurve.def("TotalLowerDistance", (Standard_Real (GeomAPI_ExtremaCurveCurve::*)()) &GeomAPI_ExtremaCurveCurve::TotalLowerDistance, "return the distance of the total nearest couple solution point. if <myExtCC> is not done");

// CLASS: GEOMAPI_EXTREMACURVESURFACE
py::class_<GeomAPI_ExtremaCurveSurface> cls_GeomAPI_ExtremaCurveSurface(mod, "GeomAPI_ExtremaCurveSurface", "Describes functions for computing all the extrema between a curve and a surface. An ExtremaCurveSurface algorithm minimizes or maximizes the distance between a point on the curve and a point on the surface. Thus, it computes start and end points of perpendiculars common to the curve and the surface (an intersection point is not an extremum except where the curve and the surface are tangential at this point). Solutions consist of pairs of points, and an extremum is considered to be a segment joining the two points of a solution. An ExtremaCurveSurface object provides a framework for: - defining the construction of the extrema, - implementing the construction algorithm, and - consulting the results. Warning In some cases, the nearest points between a curve and a surface do not correspond to one of the computed extrema. Instead, they may be given by: - a point of a bounding curve of the surface and one of the following: - its orthogonal projection on the curve, - a limit point of the curve; or - a limit point of the curve and its projection on the surface; or - an intersection point between the curve and the surface.");

// Constructors
cls_GeomAPI_ExtremaCurveSurface.def(py::init<>());
cls_GeomAPI_ExtremaCurveSurface.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &>(), py::arg("Curve"), py::arg("Surface"));
cls_GeomAPI_ExtremaCurveSurface.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Curve"), py::arg("Surface"), py::arg("Wmin"), py::arg("Wmax"), py::arg("Umin"), py::arg("Umax"), py::arg("Vmin"), py::arg("Vmax"));

// Methods
// cls_GeomAPI_ExtremaCurveSurface.def_static("operator new_", (void * (*)(size_t)) &GeomAPI_ExtremaCurveSurface::operator new, "None", py::arg("theSize"));
// cls_GeomAPI_ExtremaCurveSurface.def_static("operator delete_", (void (*)(void *)) &GeomAPI_ExtremaCurveSurface::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI_ExtremaCurveSurface.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI_ExtremaCurveSurface::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI_ExtremaCurveSurface.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI_ExtremaCurveSurface::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI_ExtremaCurveSurface.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI_ExtremaCurveSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI_ExtremaCurveSurface.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI_ExtremaCurveSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI_ExtremaCurveSurface.def("Init", (void (GeomAPI_ExtremaCurveSurface::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &)) &GeomAPI_ExtremaCurveSurface::Init, "Computes the extrema distances between the curve <C> and the surface <S>.", py::arg("Curve"), py::arg("Surface"));
cls_GeomAPI_ExtremaCurveSurface.def("Init", (void (GeomAPI_ExtremaCurveSurface::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomAPI_ExtremaCurveSurface::Init, "Computes the extrema distances between the curve <C> and the surface <S>. The solution point are computed in the domain [Wmin,Wmax] of the curve and in the domain [Umin,Umax] [Vmin,Vmax] of the surface. Warning Use the function NbExtrema to obtain the number of solutions. If this algorithm fails, NbExtrema returns 0.", py::arg("Curve"), py::arg("Surface"), py::arg("Wmin"), py::arg("Wmax"), py::arg("Umin"), py::arg("Umax"), py::arg("Vmin"), py::arg("Vmax"));
cls_GeomAPI_ExtremaCurveSurface.def("NbExtrema", (Standard_Integer (GeomAPI_ExtremaCurveSurface::*)() const) &GeomAPI_ExtremaCurveSurface::NbExtrema, "Returns the number of extrema computed by this algorithm. Note: if this algorithm fails, NbExtrema returns 0.");
cls_GeomAPI_ExtremaCurveSurface.def("Points", (void (GeomAPI_ExtremaCurveSurface::*)(const Standard_Integer, gp_Pnt &, gp_Pnt &) const) &GeomAPI_ExtremaCurveSurface::Points, "Returns the points P1 on the curve and P2 on the surface, which are the ends of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"), py::arg("P1"), py::arg("P2"));
cls_GeomAPI_ExtremaCurveSurface.def("Parameters", [](GeomAPI_ExtremaCurveSurface &self, const Standard_Integer Index, Standard_Real & W, Standard_Real & U, Standard_Real & V){ self.Parameters(Index, W, U, V); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(W, U, V); }, "Returns the parameters W of the point on the curve, and (U,V) of the point on the surface, which are the ends of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"), py::arg("W"), py::arg("U"), py::arg("V"));
cls_GeomAPI_ExtremaCurveSurface.def("Distance", (Standard_Real (GeomAPI_ExtremaCurveSurface::*)(const Standard_Integer) const) &GeomAPI_ExtremaCurveSurface::Distance, "Computes the distance between the end points of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"));
cls_GeomAPI_ExtremaCurveSurface.def("NearestPoints", (void (GeomAPI_ExtremaCurveSurface::*)(gp_Pnt &, gp_Pnt &) const) &GeomAPI_ExtremaCurveSurface::NearestPoints, "Returns the points PC on the curve and PS on the surface, which are the ends of the shortest extremum computed by this algorithm. Exceptions - StdFail_NotDone if this algorithm fails.", py::arg("PC"), py::arg("PS"));
cls_GeomAPI_ExtremaCurveSurface.def("LowerDistanceParameters", [](GeomAPI_ExtremaCurveSurface &self, Standard_Real & W, Standard_Real & U, Standard_Real & V){ self.LowerDistanceParameters(W, U, V); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(W, U, V); }, "Returns the parameters W of the point on the curve and (U,V) of the point on the surface, which are the ends of the shortest extremum computed by this algorithm. Exceptions - StdFail_NotDone if this algorithm fails.", py::arg("W"), py::arg("U"), py::arg("V"));
cls_GeomAPI_ExtremaCurveSurface.def("LowerDistance", (Standard_Real (GeomAPI_ExtremaCurveSurface::*)() const) &GeomAPI_ExtremaCurveSurface::LowerDistance, "Computes the distance between the end points of the shortest extremum computed by this algorithm. Exceptions - StdFail_NotDone if this algorithm fails.");
cls_GeomAPI_ExtremaCurveSurface.def("Extrema", (const Extrema_ExtCS & (GeomAPI_ExtremaCurveSurface::*)() const) &GeomAPI_ExtremaCurveSurface::Extrema, "Returns the algorithmic object from Extrema");

// CLASS: GEOMAPI_EXTREMASURFACESURFACE
py::class_<GeomAPI_ExtremaSurfaceSurface> cls_GeomAPI_ExtremaSurfaceSurface(mod, "GeomAPI_ExtremaSurfaceSurface", "Describes functions for computing all the extrema between two surfaces. An ExtremaSurfaceSurface algorithm minimizes or maximizes the distance between a point on the first surface and a point on the second surface. Results are start and end points of perpendiculars common to the two surfaces. Solutions consist of pairs of points, and an extremum is considered to be a segment joining the two points of a solution. An ExtremaSurfaceSurface object provides a framework for: - defining the construction of the extrema, - implementing the construction algorithm, and - consulting the results. Warning In some cases, the nearest points between the two surfaces do not correspond to one of the computed extrema. Instead, they may be given by: - a point of a bounding curve of one surface and one of the following: - its orthogonal projection on the other surface, - a point of a bounding curve of the other surface; or - any point on intersection curves between the two surfaces.");

// Constructors
cls_GeomAPI_ExtremaSurfaceSurface.def(py::init<>());
cls_GeomAPI_ExtremaSurfaceSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &>(), py::arg("S1"), py::arg("S2"));
cls_GeomAPI_ExtremaSurfaceSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("U1min"), py::arg("U1max"), py::arg("V1min"), py::arg("V1max"), py::arg("U2min"), py::arg("U2max"), py::arg("V2min"), py::arg("V2max"));

// Methods
// cls_GeomAPI_ExtremaSurfaceSurface.def_static("operator new_", (void * (*)(size_t)) &GeomAPI_ExtremaSurfaceSurface::operator new, "None", py::arg("theSize"));
// cls_GeomAPI_ExtremaSurfaceSurface.def_static("operator delete_", (void (*)(void *)) &GeomAPI_ExtremaSurfaceSurface::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI_ExtremaSurfaceSurface.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI_ExtremaSurfaceSurface::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI_ExtremaSurfaceSurface.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI_ExtremaSurfaceSurface::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI_ExtremaSurfaceSurface.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI_ExtremaSurfaceSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI_ExtremaSurfaceSurface.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI_ExtremaSurfaceSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI_ExtremaSurfaceSurface.def("Init", (void (GeomAPI_ExtremaSurfaceSurface::*)(const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &)) &GeomAPI_ExtremaSurfaceSurface::Init, "Initializes this algorithm with the given arguments and computes the extrema distances between the surfaces <S1> and <S2>", py::arg("S1"), py::arg("S2"));
cls_GeomAPI_ExtremaSurfaceSurface.def("Init", (void (GeomAPI_ExtremaSurfaceSurface::*)(const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomAPI_ExtremaSurfaceSurface::Init, "Initializes this algorithm with the given arguments and computes the extrema distances between - the portion of the surface S1 limited by the two values of parameter (U1min,U1max) in the u parametric direction, and by the two values of parameter (V1min,V1max) in the v parametric direction, and - the portion of the surface S2 limited by the two values of parameter (U2min,U2max) in the u parametric direction, and by the two values of parameter (V2min,V2max) in the v parametric direction.", py::arg("S1"), py::arg("S2"), py::arg("U1min"), py::arg("U1max"), py::arg("V1min"), py::arg("V1max"), py::arg("U2min"), py::arg("U2max"), py::arg("V2min"), py::arg("V2max"));
cls_GeomAPI_ExtremaSurfaceSurface.def("NbExtrema", (Standard_Integer (GeomAPI_ExtremaSurfaceSurface::*)() const) &GeomAPI_ExtremaSurfaceSurface::NbExtrema, "Returns the number of extrema computed by this algorithm. Note: if this algorithm fails, NbExtrema returns 0.");
cls_GeomAPI_ExtremaSurfaceSurface.def("Points", (void (GeomAPI_ExtremaSurfaceSurface::*)(const Standard_Integer, gp_Pnt &, gp_Pnt &) const) &GeomAPI_ExtremaSurfaceSurface::Points, "Returns the points P1 on the first surface and P2 on the second surface, which are the ends of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"), py::arg("P1"), py::arg("P2"));
cls_GeomAPI_ExtremaSurfaceSurface.def("Parameters", [](GeomAPI_ExtremaSurfaceSurface &self, const Standard_Integer Index, Standard_Real & U1, Standard_Real & V1, Standard_Real & U2, Standard_Real & V2){ self.Parameters(Index, U1, V1, U2, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, V1, U2, V2); }, "Returns the parameters (U1,V1) of the point on the first surface, and (U2,V2) of the point on the second surface, which are the ends of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
cls_GeomAPI_ExtremaSurfaceSurface.def("Distance", (Standard_Real (GeomAPI_ExtremaSurfaceSurface::*)(const Standard_Integer) const) &GeomAPI_ExtremaSurfaceSurface::Distance, "Computes the distance between the end points of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"));
cls_GeomAPI_ExtremaSurfaceSurface.def("NearestPoints", (void (GeomAPI_ExtremaSurfaceSurface::*)(gp_Pnt &, gp_Pnt &) const) &GeomAPI_ExtremaSurfaceSurface::NearestPoints, "Returns the points P1 on the first surface and P2 on the second surface, which are the ends of the shortest extremum computed by this algorithm. Exceptions StdFail_NotDone if this algorithm fails.", py::arg("P1"), py::arg("P2"));
cls_GeomAPI_ExtremaSurfaceSurface.def("LowerDistanceParameters", [](GeomAPI_ExtremaSurfaceSurface &self, Standard_Real & U1, Standard_Real & V1, Standard_Real & U2, Standard_Real & V2){ self.LowerDistanceParameters(U1, V1, U2, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, V1, U2, V2); }, "Returns the parameters (U1,V1) of the point on the first surface and (U2,V2) of the point on the second surface, which are the ends of the shortest extremum computed by this algorithm. Exceptions - StdFail_NotDone if this algorithm fails.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
cls_GeomAPI_ExtremaSurfaceSurface.def("LowerDistance", (Standard_Real (GeomAPI_ExtremaSurfaceSurface::*)() const) &GeomAPI_ExtremaSurfaceSurface::LowerDistance, "Computes the distance between the end points of the shortest extremum computed by this algorithm. Exceptions StdFail_NotDone if this algorithm fails.");
cls_GeomAPI_ExtremaSurfaceSurface.def("Extrema", (const Extrema_ExtSS & (GeomAPI_ExtremaSurfaceSurface::*)() const) &GeomAPI_ExtremaSurfaceSurface::Extrema, "return the algorithmic object from Extrema");

// CLASS: GEOMAPI_INTCS
py::class_<GeomAPI_IntCS> cls_GeomAPI_IntCS(mod, "GeomAPI_IntCS", "This class implements methods for computing intersection points and segments between a");

// Constructors
cls_GeomAPI_IntCS.def(py::init<>());
cls_GeomAPI_IntCS.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &>(), py::arg("C"), py::arg("S"));

// Methods
// cls_GeomAPI_IntCS.def_static("operator new_", (void * (*)(size_t)) &GeomAPI_IntCS::operator new, "None", py::arg("theSize"));
// cls_GeomAPI_IntCS.def_static("operator delete_", (void (*)(void *)) &GeomAPI_IntCS::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI_IntCS.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI_IntCS::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI_IntCS.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI_IntCS::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI_IntCS.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI_IntCS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI_IntCS.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI_IntCS::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI_IntCS.def("Perform", (void (GeomAPI_IntCS::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &)) &GeomAPI_IntCS::Perform, "This function Initializes an algorithm with the curve C and the surface S and computes the intersections between C and S. Warning Use function IsDone to verify that the intersections are computed successfully.", py::arg("C"), py::arg("S"));
cls_GeomAPI_IntCS.def("IsDone", (Standard_Boolean (GeomAPI_IntCS::*)() const) &GeomAPI_IntCS::IsDone, "Returns true if the intersections are successfully computed.");
cls_GeomAPI_IntCS.def("NbPoints", (Standard_Integer (GeomAPI_IntCS::*)() const) &GeomAPI_IntCS::NbPoints, "Returns the number of Intersection Points if IsDone returns True. else NotDone is raised.");
cls_GeomAPI_IntCS.def("Point", (const gp_Pnt & (GeomAPI_IntCS::*)(const Standard_Integer) const) &GeomAPI_IntCS::Point, "Returns the Intersection Point of range <Index>in case of cross intersection. Raises NotDone if the computation has failed or if the computation has not been done raises OutOfRange if Index is not in the range <1..NbPoints>", py::arg("Index"));
cls_GeomAPI_IntCS.def("Parameters", [](GeomAPI_IntCS &self, const Standard_Integer Index, Standard_Real & U, Standard_Real & V, Standard_Real & W){ self.Parameters(Index, U, V, W); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(U, V, W); }, "Returns parameter W on the curve and (parameters U,V) on the surface of the computed intersection point of index Index in case of cross intersection. Exceptions StdFail_NotDone if intersection algorithm fails or is not initialized. Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of computed intersection points.", py::arg("Index"), py::arg("U"), py::arg("V"), py::arg("W"));
cls_GeomAPI_IntCS.def("NbSegments", (Standard_Integer (GeomAPI_IntCS::*)() const) &GeomAPI_IntCS::NbSegments, "Returns the number of computed intersection segments in case of tangential intersection. Exceptions StdFail_NotDone if the intersection algorithm fails or is not initialized.");
cls_GeomAPI_IntCS.def("Segment", (opencascade::handle<Geom_Curve> (GeomAPI_IntCS::*)(const Standard_Integer) const) &GeomAPI_IntCS::Segment, "Returns the computed intersection segment of index Index in case of tangential intersection. Intersection segment is a portion of the initial curve tangent to surface. Exceptions StdFail_NotDone if intersection algorithm fails or is not initialized. Standard_OutOfRange if Index is not in the range [ 1,NbSegments ], where NbSegments is the number of computed intersection segments.", py::arg("Index"));
cls_GeomAPI_IntCS.def("Parameters", [](GeomAPI_IntCS &self, const Standard_Integer Index, Standard_Real & U1, Standard_Real & V1, Standard_Real & U2, Standard_Real & V2){ self.Parameters(Index, U1, V1, U2, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, V1, U2, V2); }, "Returns the parameters of the first (U1,V1) and the last (U2,V2) points of curve's segment on the surface in case of tangential intersection. Index is the number of computed intersection segments. Exceptions StdFail_NotDone if intersection algorithm fails or is not initialized. Standard_OutOfRange if Index is not in the range [ 1,NbSegments ], where NbSegments is the number of computed intersection segments.", py::arg("Index"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));

// CLASS: GEOMAPI_INTERPOLATE
py::class_<GeomAPI_Interpolate> cls_GeomAPI_Interpolate(mod, "GeomAPI_Interpolate", "This class is used to interpolate a BsplineCurve passing through an array of points, with a C2 Continuity if tangency is not requested at the point. If tangency is requested at the point the continuity will be C1. If Perodicity is requested the curve will be closed and the junction will be the first point given. The curve will than be only C1 Describes functions for building a constrained 3D BSpline curve. The curve is defined by a table of points through which it passes, and if required: - by a parallel table of reals which gives the value of the parameter of each point through which the resulting BSpline curve passes, and - by vectors tangential to these points. An Interpolate object provides a framework for: - defining the constraints of the BSpline curve, - implementing the interpolation algorithm, and - consulting the results.");

// Constructors
cls_GeomAPI_Interpolate.def(py::init<const opencascade::handle<TColgp_HArray1OfPnt> &, const Standard_Boolean, const Standard_Real>(), py::arg("Points"), py::arg("PeriodicFlag"), py::arg("Tolerance"));
cls_GeomAPI_Interpolate.def(py::init<const opencascade::handle<TColgp_HArray1OfPnt> &, const opencascade::handle<TColStd_HArray1OfReal> &, const Standard_Boolean, const Standard_Real>(), py::arg("Points"), py::arg("Parameters"), py::arg("PeriodicFlag"), py::arg("Tolerance"));

// Methods
// cls_GeomAPI_Interpolate.def_static("operator new_", (void * (*)(size_t)) &GeomAPI_Interpolate::operator new, "None", py::arg("theSize"));
// cls_GeomAPI_Interpolate.def_static("operator delete_", (void (*)(void *)) &GeomAPI_Interpolate::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI_Interpolate.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI_Interpolate::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI_Interpolate.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI_Interpolate::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI_Interpolate.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI_Interpolate::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI_Interpolate.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI_Interpolate::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI_Interpolate.def("Load", [](GeomAPI_Interpolate &self, const gp_Vec & a0, const gp_Vec & a1) -> void { return self.Load(a0, a1); });
cls_GeomAPI_Interpolate.def("Load", (void (GeomAPI_Interpolate::*)(const gp_Vec &, const gp_Vec &, const Standard_Boolean)) &GeomAPI_Interpolate::Load, "Assigns this constrained BSpline curve to be tangential to vectors InitialTangent and FinalTangent at its first and last points respectively (i.e. the first and last points of the table of points through which the curve passes, as defined at the time of initialization).", py::arg("InitialTangent"), py::arg("FinalTangent"), py::arg("Scale"));
cls_GeomAPI_Interpolate.def("Load", [](GeomAPI_Interpolate &self, const TColgp_Array1OfVec & a0, const opencascade::handle<TColStd_HArray1OfBoolean> & a1) -> void { return self.Load(a0, a1); });
cls_GeomAPI_Interpolate.def("Load", (void (GeomAPI_Interpolate::*)(const TColgp_Array1OfVec &, const opencascade::handle<TColStd_HArray1OfBoolean> &, const Standard_Boolean)) &GeomAPI_Interpolate::Load, "Assigns this constrained BSpline curve to be tangential to vectors defined in the table Tangents, which is parallel to the table of points through which the curve passes, as defined at the time of initialization. Vectors in the table Tangents are defined only if the flag given in the parallel table TangentFlags is true: only these vectors are set as tangency constraints.", py::arg("Tangents"), py::arg("TangentFlags"), py::arg("Scale"));
// cls_GeomAPI_Interpolate.def("ClearTangents", (void (GeomAPI_Interpolate::*)()) &GeomAPI_Interpolate::ClearTangents, "Clears all tangency constraints on this constrained BSpline curve (as initialized by the function Load).");
cls_GeomAPI_Interpolate.def("Perform", (void (GeomAPI_Interpolate::*)()) &GeomAPI_Interpolate::Perform, "Computes the constrained BSpline curve. Use the function IsDone to verify that the computation is successful, and then the function Curve to obtain the result.");
cls_GeomAPI_Interpolate.def("Curve", (const opencascade::handle<Geom_BSplineCurve> & (GeomAPI_Interpolate::*)() const) &GeomAPI_Interpolate::Curve, "Returns the computed BSpline curve. Raises StdFail_NotDone if the interpolation fails.");
cls_GeomAPI_Interpolate.def("IsDone", (Standard_Boolean (GeomAPI_Interpolate::*)() const) &GeomAPI_Interpolate::IsDone, "Returns true if the constrained BSpline curve is successfully constructed. Note: in this case, the result is given by the function Curve.");

// CLASS: GEOMAPI_INTSS
py::class_<GeomAPI_IntSS> cls_GeomAPI_IntSS(mod, "GeomAPI_IntSS", "This class implements methods for computing the intersection curves between two surfaces. The result is curves from Geom. The 'domain' used for a surface is the natural parametric domain unless the surface is a RectangularTrimmedSurface from Geom.");

// Constructors
cls_GeomAPI_IntSS.def(py::init<>());
cls_GeomAPI_IntSS.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("Tol"));

// Methods
// cls_GeomAPI_IntSS.def_static("operator new_", (void * (*)(size_t)) &GeomAPI_IntSS::operator new, "None", py::arg("theSize"));
// cls_GeomAPI_IntSS.def_static("operator delete_", (void (*)(void *)) &GeomAPI_IntSS::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI_IntSS.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI_IntSS::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI_IntSS.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI_IntSS::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI_IntSS.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI_IntSS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI_IntSS.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI_IntSS::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI_IntSS.def("Perform", (void (GeomAPI_IntSS::*)(const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const Standard_Real)) &GeomAPI_IntSS::Perform, "Initializes an algorithm with the given arguments and computes the intersection curves between the two surfaces S1 and S2. Parameter Tol defines the precision of curves computation. For most cases the value 1.0e-7 is recommended to use. Warning Use function IsDone to verify that the intersections are successfully computed.", py::arg("S1"), py::arg("S2"), py::arg("Tol"));
cls_GeomAPI_IntSS.def("IsDone", (Standard_Boolean (GeomAPI_IntSS::*)() const) &GeomAPI_IntSS::IsDone, "Returns True if the intersection was successful.");
cls_GeomAPI_IntSS.def("NbLines", (Standard_Integer (GeomAPI_IntSS::*)() const) &GeomAPI_IntSS::NbLines, "Returns the number of computed intersection curves. Exceptions StdFail_NotDone if the computation fails.");
cls_GeomAPI_IntSS.def("Line", (const opencascade::handle<Geom_Curve> & (GeomAPI_IntSS::*)(const Standard_Integer) const) &GeomAPI_IntSS::Line, "Returns the computed intersection curve of index Index. Exceptions StdFail_NotDone if the computation fails. Standard_OutOfRange if Index is out of range [1, NbLines] where NbLines is the number of computed intersection curves.", py::arg("Index"));

// CLASS: GEOMAPI_POINTSTOBSPLINE
py::class_<GeomAPI_PointsToBSpline> cls_GeomAPI_PointsToBSpline(mod, "GeomAPI_PointsToBSpline", "This class is used to approximate a BsplineCurve passing through an array of points, with a given Continuity. Describes functions for building a 3D BSpline curve which approximates a set of points. A PointsToBSpline object provides a framework for: - defining the data of the BSpline curve to be built, - implementing the approximation algorithm, and consulting the results.");

// Constructors
cls_GeomAPI_PointsToBSpline.def(py::init<>());
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &>(), py::arg("Points"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Standard_Integer>(), py::arg("Points"), py::arg("DegMin"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Standard_Integer, const Standard_Integer>(), py::arg("Points"), py::arg("DegMin"), py::arg("DegMax"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape>(), py::arg("Points"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real>(), py::arg("Points"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Approx_ParametrizationType>(), py::arg("Points"), py::arg("ParType"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Approx_ParametrizationType, const Standard_Integer>(), py::arg("Points"), py::arg("ParType"), py::arg("DegMin"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Approx_ParametrizationType, const Standard_Integer, const Standard_Integer>(), py::arg("Points"), py::arg("ParType"), py::arg("DegMin"), py::arg("DegMax"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Approx_ParametrizationType, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape>(), py::arg("Points"), py::arg("ParType"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Approx_ParametrizationType, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real>(), py::arg("Points"), py::arg("ParType"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &>(), py::arg("Points"), py::arg("Parameters"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const Standard_Integer>(), py::arg("Points"), py::arg("Parameters"), py::arg("DegMin"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const Standard_Integer, const Standard_Integer>(), py::arg("Points"), py::arg("Parameters"), py::arg("DegMin"), py::arg("DegMax"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape>(), py::arg("Points"), py::arg("Parameters"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real>(), py::arg("Points"), py::arg("Parameters"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Points"), py::arg("Weight1"), py::arg("Weight2"), py::arg("Weight3"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Points"), py::arg("Weight1"), py::arg("Weight2"), py::arg("Weight3"), py::arg("DegMax"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const GeomAbs_Shape>(), py::arg("Points"), py::arg("Weight1"), py::arg("Weight2"), py::arg("Weight3"), py::arg("DegMax"), py::arg("Continuity"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const GeomAbs_Shape, const Standard_Real>(), py::arg("Points"), py::arg("Weight1"), py::arg("Weight2"), py::arg("Weight3"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));

// Methods
// cls_GeomAPI_PointsToBSpline.def_static("operator new_", (void * (*)(size_t)) &GeomAPI_PointsToBSpline::operator new, "None", py::arg("theSize"));
// cls_GeomAPI_PointsToBSpline.def_static("operator delete_", (void (*)(void *)) &GeomAPI_PointsToBSpline::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI_PointsToBSpline.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI_PointsToBSpline::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI_PointsToBSpline.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI_PointsToBSpline::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI_PointsToBSpline.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI_PointsToBSpline::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI_PointsToBSpline.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI_PointsToBSpline::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0) -> void { return self.Init(a0); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Standard_Integer a1) -> void { return self.Init(a0, a1); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Standard_Integer a1, const Standard_Integer a2) -> void { return self.Init(a0, a1, a2); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Standard_Integer a1, const Standard_Integer a2, const GeomAbs_Shape a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_GeomAPI_PointsToBSpline.def("Init", (void (GeomAPI_PointsToBSpline::*)(const TColgp_Array1OfPnt &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real)) &GeomAPI_PointsToBSpline::Init, "Approximate a BSpline Curve passing through an array of Point. The resulting BSpline will have the following properties: 1- his degree will be in the range [Degmin,Degmax] 2- his continuity will be at least <Continuity> 3- the distance from the point <Points> to the BSpline will be lower to Tol3D", py::arg("Points"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Approx_ParametrizationType a1) -> void { return self.Init(a0, a1); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Approx_ParametrizationType a1, const Standard_Integer a2) -> void { return self.Init(a0, a1, a2); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Approx_ParametrizationType a1, const Standard_Integer a2, const Standard_Integer a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Approx_ParametrizationType a1, const Standard_Integer a2, const Standard_Integer a3, const GeomAbs_Shape a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_GeomAPI_PointsToBSpline.def("Init", (void (GeomAPI_PointsToBSpline::*)(const TColgp_Array1OfPnt &, const Approx_ParametrizationType, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real)) &GeomAPI_PointsToBSpline::Init, "Approximate a BSpline Curve passing through an array of Point. The resulting BSpline will have the following properties: 1- his degree will be in the range [Degmin,Degmax] 2- his continuity will be at least <Continuity> 3- the distance from the point <Points> to the BSpline will be lower to Tol3D", py::arg("Points"), py::arg("ParType"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const TColStd_Array1OfReal & a1) -> void { return self.Init(a0, a1); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const TColStd_Array1OfReal & a1, const Standard_Integer a2) -> void { return self.Init(a0, a1, a2); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const TColStd_Array1OfReal & a1, const Standard_Integer a2, const Standard_Integer a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const TColStd_Array1OfReal & a1, const Standard_Integer a2, const Standard_Integer a3, const GeomAbs_Shape a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_GeomAPI_PointsToBSpline.def("Init", (void (GeomAPI_PointsToBSpline::*)(const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real)) &GeomAPI_PointsToBSpline::Init, "Approximate a BSpline Curve passing through an array of Point, which parameters are given by the array <Parameters>. The resulting BSpline will have the following properties: 1- his degree will be in the range [Degmin,Degmax] 2- his continuity will be at least <Continuity> 3- the distance from the point <Points> to the BSpline will be lower to Tol3D", py::arg("Points"), py::arg("Parameters"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4, const GeomAbs_Shape a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); });
cls_GeomAPI_PointsToBSpline.def("Init", (void (GeomAPI_PointsToBSpline::*)(const TColgp_Array1OfPnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const GeomAbs_Shape, const Standard_Real)) &GeomAPI_PointsToBSpline::Init, "Approximate a BSpline Curve passing through an array of Point using variational smoothing algorithm, which tries to minimize additional criterium: Weight1*CurveLength + Weight2*Curvature + Weight3*Torsion", py::arg("Points"), py::arg("Weight1"), py::arg("Weight2"), py::arg("Weight3"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSpline.def("Curve", (const opencascade::handle<Geom_BSplineCurve> & (GeomAPI_PointsToBSpline::*)() const) &GeomAPI_PointsToBSpline::Curve, "Returns the computed BSpline curve. Raises StdFail_NotDone if the curve is not built.");
cls_GeomAPI_PointsToBSpline.def("IsDone", (Standard_Boolean (GeomAPI_PointsToBSpline::*)() const) &GeomAPI_PointsToBSpline::IsDone, "None");

// CLASS: GEOMAPI_POINTSTOBSPLINESURFACE
py::class_<GeomAPI_PointsToBSplineSurface> cls_GeomAPI_PointsToBSplineSurface(mod, "GeomAPI_PointsToBSplineSurface", "This class is used to approximate or interpolate a BSplineSurface passing through an Array2 of points, with a given continuity. Describes functions for building a BSpline surface which approximates or interpolates a set of points. A PointsToBSplineSurface object provides a framework for: - defining the data of the BSpline surface to be built, - implementing the approximation algorithm or the interpolation algorithm, and consulting the results.");

// Constructors
cls_GeomAPI_PointsToBSplineSurface.def(py::init<>());
cls_GeomAPI_PointsToBSplineSurface.def(py::init<const TColgp_Array2OfPnt &>(), py::arg("Points"));
cls_GeomAPI_PointsToBSplineSurface.def(py::init<const TColgp_Array2OfPnt &, const Standard_Integer>(), py::arg("Points"), py::arg("DegMin"));
cls_GeomAPI_PointsToBSplineSurface.def(py::init<const TColgp_Array2OfPnt &, const Standard_Integer, const Standard_Integer>(), py::arg("Points"), py::arg("DegMin"), py::arg("DegMax"));
cls_GeomAPI_PointsToBSplineSurface.def(py::init<const TColgp_Array2OfPnt &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape>(), py::arg("Points"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"));
cls_GeomAPI_PointsToBSplineSurface.def(py::init<const TColgp_Array2OfPnt &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real>(), py::arg("Points"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSplineSurface.def(py::init<const TColgp_Array2OfPnt &, const Approx_ParametrizationType>(), py::arg("Points"), py::arg("ParType"));
cls_GeomAPI_PointsToBSplineSurface.def(py::init<const TColgp_Array2OfPnt &, const Approx_ParametrizationType, const Standard_Integer>(), py::arg("Points"), py::arg("ParType"), py::arg("DegMin"));
cls_GeomAPI_PointsToBSplineSurface.def(py::init<const TColgp_Array2OfPnt &, const Approx_ParametrizationType, const Standard_Integer, const Standard_Integer>(), py::arg("Points"), py::arg("ParType"), py::arg("DegMin"), py::arg("DegMax"));
cls_GeomAPI_PointsToBSplineSurface.def(py::init<const TColgp_Array2OfPnt &, const Approx_ParametrizationType, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape>(), py::arg("Points"), py::arg("ParType"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"));
cls_GeomAPI_PointsToBSplineSurface.def(py::init<const TColgp_Array2OfPnt &, const Approx_ParametrizationType, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real>(), py::arg("Points"), py::arg("ParType"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSplineSurface.def(py::init<const TColgp_Array2OfPnt &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Points"), py::arg("Weight1"), py::arg("Weight2"), py::arg("Weight3"));
cls_GeomAPI_PointsToBSplineSurface.def(py::init<const TColgp_Array2OfPnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Points"), py::arg("Weight1"), py::arg("Weight2"), py::arg("Weight3"), py::arg("DegMax"));
cls_GeomAPI_PointsToBSplineSurface.def(py::init<const TColgp_Array2OfPnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const GeomAbs_Shape>(), py::arg("Points"), py::arg("Weight1"), py::arg("Weight2"), py::arg("Weight3"), py::arg("DegMax"), py::arg("Continuity"));
cls_GeomAPI_PointsToBSplineSurface.def(py::init<const TColgp_Array2OfPnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const GeomAbs_Shape, const Standard_Real>(), py::arg("Points"), py::arg("Weight1"), py::arg("Weight2"), py::arg("Weight3"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSplineSurface.def(py::init<const TColStd_Array2OfReal &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("ZPoints"), py::arg("X0"), py::arg("dX"), py::arg("Y0"), py::arg("dY"));
cls_GeomAPI_PointsToBSplineSurface.def(py::init<const TColStd_Array2OfReal &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("ZPoints"), py::arg("X0"), py::arg("dX"), py::arg("Y0"), py::arg("dY"), py::arg("DegMin"));
cls_GeomAPI_PointsToBSplineSurface.def(py::init<const TColStd_Array2OfReal &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("ZPoints"), py::arg("X0"), py::arg("dX"), py::arg("Y0"), py::arg("dY"), py::arg("DegMin"), py::arg("DegMax"));
cls_GeomAPI_PointsToBSplineSurface.def(py::init<const TColStd_Array2OfReal &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape>(), py::arg("ZPoints"), py::arg("X0"), py::arg("dX"), py::arg("Y0"), py::arg("dY"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"));
cls_GeomAPI_PointsToBSplineSurface.def(py::init<const TColStd_Array2OfReal &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real>(), py::arg("ZPoints"), py::arg("X0"), py::arg("dX"), py::arg("Y0"), py::arg("dY"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));

// Methods
// cls_GeomAPI_PointsToBSplineSurface.def_static("operator new_", (void * (*)(size_t)) &GeomAPI_PointsToBSplineSurface::operator new, "None", py::arg("theSize"));
// cls_GeomAPI_PointsToBSplineSurface.def_static("operator delete_", (void (*)(void *)) &GeomAPI_PointsToBSplineSurface::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI_PointsToBSplineSurface.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI_PointsToBSplineSurface::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI_PointsToBSplineSurface.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI_PointsToBSplineSurface::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI_PointsToBSplineSurface.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI_PointsToBSplineSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI_PointsToBSplineSurface.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI_PointsToBSplineSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI_PointsToBSplineSurface.def("Init", [](GeomAPI_PointsToBSplineSurface &self, const TColgp_Array2OfPnt & a0) -> void { return self.Init(a0); });
cls_GeomAPI_PointsToBSplineSurface.def("Init", [](GeomAPI_PointsToBSplineSurface &self, const TColgp_Array2OfPnt & a0, const Standard_Integer a1) -> void { return self.Init(a0, a1); });
cls_GeomAPI_PointsToBSplineSurface.def("Init", [](GeomAPI_PointsToBSplineSurface &self, const TColgp_Array2OfPnt & a0, const Standard_Integer a1, const Standard_Integer a2) -> void { return self.Init(a0, a1, a2); });
cls_GeomAPI_PointsToBSplineSurface.def("Init", [](GeomAPI_PointsToBSplineSurface &self, const TColgp_Array2OfPnt & a0, const Standard_Integer a1, const Standard_Integer a2, const GeomAbs_Shape a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_GeomAPI_PointsToBSplineSurface.def("Init", (void (GeomAPI_PointsToBSplineSurface::*)(const TColgp_Array2OfPnt &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real)) &GeomAPI_PointsToBSplineSurface::Init, "Approximates a BSpline Surface passing through an array of Point. The resulting BSpline will have the following properties: 1- his degree will be in the range [Degmin,Degmax] 2- his continuity will be at least <Continuity> 3- the distance from the point <Points> to the BSpline will be lower to Tol3D", py::arg("Points"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSplineSurface.def("Interpolate", (void (GeomAPI_PointsToBSplineSurface::*)(const TColgp_Array2OfPnt &)) &GeomAPI_PointsToBSplineSurface::Interpolate, "Interpolates a BSpline Surface passing through an array of Point. The resulting BSpline will have the following properties: 1- his degree will be 3. 2- his continuity will be C2.", py::arg("Points"));
cls_GeomAPI_PointsToBSplineSurface.def("Interpolate", (void (GeomAPI_PointsToBSplineSurface::*)(const TColgp_Array2OfPnt &, const Approx_ParametrizationType)) &GeomAPI_PointsToBSplineSurface::Interpolate, "Interpolates a BSpline Surface passing through an array of Point. The resulting BSpline will have the following properties: 1- his degree will be 3. 2- his continuity will be C2.", py::arg("Points"), py::arg("ParType"));
cls_GeomAPI_PointsToBSplineSurface.def("Init", [](GeomAPI_PointsToBSplineSurface &self, const TColStd_Array2OfReal & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_GeomAPI_PointsToBSplineSurface.def("Init", [](GeomAPI_PointsToBSplineSurface &self, const TColStd_Array2OfReal & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Integer a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); });
cls_GeomAPI_PointsToBSplineSurface.def("Init", [](GeomAPI_PointsToBSplineSurface &self, const TColStd_Array2OfReal & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Integer a5, const Standard_Integer a6) -> void { return self.Init(a0, a1, a2, a3, a4, a5, a6); });
cls_GeomAPI_PointsToBSplineSurface.def("Init", [](GeomAPI_PointsToBSplineSurface &self, const TColStd_Array2OfReal & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Integer a5, const Standard_Integer a6, const GeomAbs_Shape a7) -> void { return self.Init(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_GeomAPI_PointsToBSplineSurface.def("Init", (void (GeomAPI_PointsToBSplineSurface::*)(const TColStd_Array2OfReal &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real)) &GeomAPI_PointsToBSplineSurface::Init, "Approximates a BSpline Surface passing through an array of Points.", py::arg("ZPoints"), py::arg("X0"), py::arg("dX"), py::arg("Y0"), py::arg("dY"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSplineSurface.def("Interpolate", (void (GeomAPI_PointsToBSplineSurface::*)(const TColStd_Array2OfReal &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomAPI_PointsToBSplineSurface::Interpolate, "Interpolates a BSpline Surface passing through an array of Points.", py::arg("ZPoints"), py::arg("X0"), py::arg("dX"), py::arg("Y0"), py::arg("dY"));
cls_GeomAPI_PointsToBSplineSurface.def("Init", [](GeomAPI_PointsToBSplineSurface &self, const TColgp_Array2OfPnt & a0, const Approx_ParametrizationType a1) -> void { return self.Init(a0, a1); });
cls_GeomAPI_PointsToBSplineSurface.def("Init", [](GeomAPI_PointsToBSplineSurface &self, const TColgp_Array2OfPnt & a0, const Approx_ParametrizationType a1, const Standard_Integer a2) -> void { return self.Init(a0, a1, a2); });
cls_GeomAPI_PointsToBSplineSurface.def("Init", [](GeomAPI_PointsToBSplineSurface &self, const TColgp_Array2OfPnt & a0, const Approx_ParametrizationType a1, const Standard_Integer a2, const Standard_Integer a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_GeomAPI_PointsToBSplineSurface.def("Init", [](GeomAPI_PointsToBSplineSurface &self, const TColgp_Array2OfPnt & a0, const Approx_ParametrizationType a1, const Standard_Integer a2, const Standard_Integer a3, const GeomAbs_Shape a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_GeomAPI_PointsToBSplineSurface.def("Init", (void (GeomAPI_PointsToBSplineSurface::*)(const TColgp_Array2OfPnt &, const Approx_ParametrizationType, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real)) &GeomAPI_PointsToBSplineSurface::Init, "Approximates a BSpline Surface passing through an array of Point. The resulting BSpline will have the following properties: 1- his degree will be in the range [Degmin,Degmax] 2- his continuity will be at least <Continuity> 3- the distance from the point <Points> to the BSpline will be lower to Tol3D", py::arg("Points"), py::arg("ParType"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSplineSurface.def("Init", [](GeomAPI_PointsToBSplineSurface &self, const TColgp_Array2OfPnt & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_GeomAPI_PointsToBSplineSurface.def("Init", [](GeomAPI_PointsToBSplineSurface &self, const TColgp_Array2OfPnt & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_GeomAPI_PointsToBSplineSurface.def("Init", [](GeomAPI_PointsToBSplineSurface &self, const TColgp_Array2OfPnt & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4, const GeomAbs_Shape a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); });
cls_GeomAPI_PointsToBSplineSurface.def("Init", (void (GeomAPI_PointsToBSplineSurface::*)(const TColgp_Array2OfPnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const GeomAbs_Shape, const Standard_Real)) &GeomAPI_PointsToBSplineSurface::Init, "Approximates a BSpline Surface passing through an array of point using variational smoothing algorithm, which tries to minimize additional criterium: Weight1*CurveLength + Weight2*Curvature + Weight3*Torsion", py::arg("Points"), py::arg("Weight1"), py::arg("Weight2"), py::arg("Weight3"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSplineSurface.def("Surface", (const opencascade::handle<Geom_BSplineSurface> & (GeomAPI_PointsToBSplineSurface::*)() const) &GeomAPI_PointsToBSplineSurface::Surface, "Returns the approximate BSpline Surface");
cls_GeomAPI_PointsToBSplineSurface.def("IsDone", (Standard_Boolean (GeomAPI_PointsToBSplineSurface::*)() const) &GeomAPI_PointsToBSplineSurface::IsDone, "None");

// CLASS: GEOMAPI_PROJECTPOINTONCURVE
py::class_<GeomAPI_ProjectPointOnCurve> cls_GeomAPI_ProjectPointOnCurve(mod, "GeomAPI_ProjectPointOnCurve", "This class implements methods for computing all the orthogonal projections of a 3D point onto a 3D curve.");

// Constructors
cls_GeomAPI_ProjectPointOnCurve.def(py::init<>());
cls_GeomAPI_ProjectPointOnCurve.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Curve> &>(), py::arg("P"), py::arg("Curve"));
cls_GeomAPI_ProjectPointOnCurve.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("Curve"), py::arg("Umin"), py::arg("Usup"));

// Methods
// cls_GeomAPI_ProjectPointOnCurve.def_static("operator new_", (void * (*)(size_t)) &GeomAPI_ProjectPointOnCurve::operator new, "None", py::arg("theSize"));
// cls_GeomAPI_ProjectPointOnCurve.def_static("operator delete_", (void (*)(void *)) &GeomAPI_ProjectPointOnCurve::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI_ProjectPointOnCurve.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI_ProjectPointOnCurve::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI_ProjectPointOnCurve.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI_ProjectPointOnCurve::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI_ProjectPointOnCurve.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI_ProjectPointOnCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI_ProjectPointOnCurve.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI_ProjectPointOnCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI_ProjectPointOnCurve.def("Init", (void (GeomAPI_ProjectPointOnCurve::*)(const gp_Pnt &, const opencascade::handle<Geom_Curve> &)) &GeomAPI_ProjectPointOnCurve::Init, "Init the projection of a point <P> on a curve <Curve>", py::arg("P"), py::arg("Curve"));
cls_GeomAPI_ProjectPointOnCurve.def("Init", (void (GeomAPI_ProjectPointOnCurve::*)(const gp_Pnt &, const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real)) &GeomAPI_ProjectPointOnCurve::Init, "Init the projection of a point <P> on a curve <Curve> limited by the two points of parameter Umin and Usup.", py::arg("P"), py::arg("Curve"), py::arg("Umin"), py::arg("Usup"));
cls_GeomAPI_ProjectPointOnCurve.def("Init", (void (GeomAPI_ProjectPointOnCurve::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real)) &GeomAPI_ProjectPointOnCurve::Init, "Init the projection of a point <P> on a curve <Curve> limited by the two points of parameter Umin and Usup.", py::arg("Curve"), py::arg("Umin"), py::arg("Usup"));
cls_GeomAPI_ProjectPointOnCurve.def("Perform", (void (GeomAPI_ProjectPointOnCurve::*)(const gp_Pnt &)) &GeomAPI_ProjectPointOnCurve::Perform, "Performs the projection of a point on the current curve.", py::arg("P"));
cls_GeomAPI_ProjectPointOnCurve.def("NbPoints", (Standard_Integer (GeomAPI_ProjectPointOnCurve::*)() const) &GeomAPI_ProjectPointOnCurve::NbPoints, "Returns the number of computed orthogonal projection points. Note: if this algorithm fails, NbPoints returns 0.");
cls_GeomAPI_ProjectPointOnCurve.def("Point", (gp_Pnt (GeomAPI_ProjectPointOnCurve::*)(const Standard_Integer) const) &GeomAPI_ProjectPointOnCurve::Point, "Returns the orthogonal projection on the curve. Index is a number of a computed point. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of solution points.", py::arg("Index"));
cls_GeomAPI_ProjectPointOnCurve.def("Parameter", (Standard_Real (GeomAPI_ProjectPointOnCurve::*)(const Standard_Integer) const) &GeomAPI_ProjectPointOnCurve::Parameter, "Returns the parameter on the curve of the point, which is the orthogonal projection. Index is a number of a computed point. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of solution points.", py::arg("Index"));
cls_GeomAPI_ProjectPointOnCurve.def("Parameter", [](GeomAPI_ProjectPointOnCurve &self, const Standard_Integer Index, Standard_Real & U){ self.Parameter(Index, U); return U; }, "Returns the parameter on the curve of the point, which is the orthogonal projection. Index is a number of a computed point. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of solution points.-", py::arg("Index"), py::arg("U"));
cls_GeomAPI_ProjectPointOnCurve.def("Distance", (Standard_Real (GeomAPI_ProjectPointOnCurve::*)(const Standard_Integer) const) &GeomAPI_ProjectPointOnCurve::Distance, "Computes the distance between the point and its orthogonal projection on the curve. Index is a number of a computed point. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of solution points.", py::arg("Index"));
cls_GeomAPI_ProjectPointOnCurve.def("NearestPoint", (gp_Pnt (GeomAPI_ProjectPointOnCurve::*)() const) &GeomAPI_ProjectPointOnCurve::NearestPoint, "Returns the nearest orthogonal projection of the point on the curve. Exceptions: StdFail_NotDone if this algorithm fails.");
cls_GeomAPI_ProjectPointOnCurve.def("LowerDistanceParameter", (Standard_Real (GeomAPI_ProjectPointOnCurve::*)() const) &GeomAPI_ProjectPointOnCurve::LowerDistanceParameter, "Returns the parameter on the curve of the nearest orthogonal projection of the point. Exceptions: StdFail_NotDone if this algorithm fails.");
cls_GeomAPI_ProjectPointOnCurve.def("LowerDistance", (Standard_Real (GeomAPI_ProjectPointOnCurve::*)() const) &GeomAPI_ProjectPointOnCurve::LowerDistance, "Computes the distance between the point and its nearest orthogonal projection on the curve. Exceptions: StdFail_NotDone if this algorithm fails.");
cls_GeomAPI_ProjectPointOnCurve.def("Extrema", (const Extrema_ExtPC & (GeomAPI_ProjectPointOnCurve::*)() const) &GeomAPI_ProjectPointOnCurve::Extrema, "return the algorithmic object from Extrema");

// CLASS: GEOMAPI_PROJECTPOINTONSURF
py::class_<GeomAPI_ProjectPointOnSurf> cls_GeomAPI_ProjectPointOnSurf(mod, "GeomAPI_ProjectPointOnSurf", "This class implements methods for computing all the orthogonal projections of a point onto a surface.");

// Constructors
cls_GeomAPI_ProjectPointOnSurf.def(py::init<>());
cls_GeomAPI_ProjectPointOnSurf.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Surface> &>(), py::arg("P"), py::arg("Surface"));
cls_GeomAPI_ProjectPointOnSurf.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Extrema_ExtAlgo>(), py::arg("P"), py::arg("Surface"), py::arg("Algo"));
cls_GeomAPI_ProjectPointOnSurf.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("P"), py::arg("Surface"), py::arg("Tolerance"));
cls_GeomAPI_ProjectPointOnSurf.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Extrema_ExtAlgo>(), py::arg("P"), py::arg("Surface"), py::arg("Tolerance"), py::arg("Algo"));
cls_GeomAPI_ProjectPointOnSurf.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("Surface"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("Tolerance"));
cls_GeomAPI_ProjectPointOnSurf.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtAlgo>(), py::arg("P"), py::arg("Surface"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("Tolerance"), py::arg("Algo"));
cls_GeomAPI_ProjectPointOnSurf.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("Surface"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"));
cls_GeomAPI_ProjectPointOnSurf.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtAlgo>(), py::arg("P"), py::arg("Surface"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("Algo"));

// Methods
// cls_GeomAPI_ProjectPointOnSurf.def_static("operator new_", (void * (*)(size_t)) &GeomAPI_ProjectPointOnSurf::operator new, "None", py::arg("theSize"));
// cls_GeomAPI_ProjectPointOnSurf.def_static("operator delete_", (void (*)(void *)) &GeomAPI_ProjectPointOnSurf::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI_ProjectPointOnSurf.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI_ProjectPointOnSurf::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI_ProjectPointOnSurf.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI_ProjectPointOnSurf::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI_ProjectPointOnSurf.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI_ProjectPointOnSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI_ProjectPointOnSurf.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI_ProjectPointOnSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI_ProjectPointOnSurf.def("Init", [](GeomAPI_ProjectPointOnSurf &self, const gp_Pnt & a0, const opencascade::handle<Geom_Surface> & a1, const Standard_Real a2) -> void { return self.Init(a0, a1, a2); });
cls_GeomAPI_ProjectPointOnSurf.def("Init", (void (GeomAPI_ProjectPointOnSurf::*)(const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Extrema_ExtAlgo)) &GeomAPI_ProjectPointOnSurf::Init, "None", py::arg("P"), py::arg("Surface"), py::arg("Tolerance"), py::arg("Algo"));
cls_GeomAPI_ProjectPointOnSurf.def("Init", [](GeomAPI_ProjectPointOnSurf &self, const gp_Pnt & a0, const opencascade::handle<Geom_Surface> & a1) -> void { return self.Init(a0, a1); });
cls_GeomAPI_ProjectPointOnSurf.def("Init", (void (GeomAPI_ProjectPointOnSurf::*)(const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Extrema_ExtAlgo)) &GeomAPI_ProjectPointOnSurf::Init, "Init the projection of a point <P> on a surface <Surface>. The solution are computed in the domain [Umin,Usup] [Vmin,Vsup] of the surface.", py::arg("P"), py::arg("Surface"), py::arg("Algo"));
cls_GeomAPI_ProjectPointOnSurf.def("Init", [](GeomAPI_ProjectPointOnSurf &self, const gp_Pnt & a0, const opencascade::handle<Geom_Surface> & a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5, const Standard_Real a6) -> void { return self.Init(a0, a1, a2, a3, a4, a5, a6); });
cls_GeomAPI_ProjectPointOnSurf.def("Init", (void (GeomAPI_ProjectPointOnSurf::*)(const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtAlgo)) &GeomAPI_ProjectPointOnSurf::Init, "None", py::arg("P"), py::arg("Surface"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("Tolerance"), py::arg("Algo"));
cls_GeomAPI_ProjectPointOnSurf.def("Init", [](GeomAPI_ProjectPointOnSurf &self, const gp_Pnt & a0, const opencascade::handle<Geom_Surface> & a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); });
cls_GeomAPI_ProjectPointOnSurf.def("Init", (void (GeomAPI_ProjectPointOnSurf::*)(const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtAlgo)) &GeomAPI_ProjectPointOnSurf::Init, "Init the projection for many points on a surface <Surface>. The solutions will be computed in the domain [Umin,Usup] [Vmin,Vsup] of the surface.", py::arg("P"), py::arg("Surface"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("Algo"));
cls_GeomAPI_ProjectPointOnSurf.def("Init", [](GeomAPI_ProjectPointOnSurf &self, const opencascade::handle<Geom_Surface> & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); });
cls_GeomAPI_ProjectPointOnSurf.def("Init", (void (GeomAPI_ProjectPointOnSurf::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtAlgo)) &GeomAPI_ProjectPointOnSurf::Init, "None", py::arg("Surface"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("Tolerance"), py::arg("Algo"));
cls_GeomAPI_ProjectPointOnSurf.def("Init", [](GeomAPI_ProjectPointOnSurf &self, const opencascade::handle<Geom_Surface> & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_GeomAPI_ProjectPointOnSurf.def("Init", (void (GeomAPI_ProjectPointOnSurf::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtAlgo)) &GeomAPI_ProjectPointOnSurf::Init, "None", py::arg("Surface"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("Algo"));
cls_GeomAPI_ProjectPointOnSurf.def("SetExtremaAlgo", (void (GeomAPI_ProjectPointOnSurf::*)(const Extrema_ExtAlgo)) &GeomAPI_ProjectPointOnSurf::SetExtremaAlgo, "Sets the Extrema search algorithm - Grad or Tree. By default the Extrema is initialized with Grad algorithm.", py::arg("theAlgo"));
cls_GeomAPI_ProjectPointOnSurf.def("SetExtremaFlag", (void (GeomAPI_ProjectPointOnSurf::*)(const Extrema_ExtFlag)) &GeomAPI_ProjectPointOnSurf::SetExtremaFlag, "Sets the Extrema search flag - MIN or MAX or MINMAX. By default the Extrema is set to search the MinMax solutions.", py::arg("theExtFlag"));
cls_GeomAPI_ProjectPointOnSurf.def("Perform", (void (GeomAPI_ProjectPointOnSurf::*)(const gp_Pnt &)) &GeomAPI_ProjectPointOnSurf::Perform, "Performs the projection of a point on the current surface.", py::arg("P"));
cls_GeomAPI_ProjectPointOnSurf.def("IsDone", (Standard_Boolean (GeomAPI_ProjectPointOnSurf::*)() const) &GeomAPI_ProjectPointOnSurf::IsDone, "None");
cls_GeomAPI_ProjectPointOnSurf.def("NbPoints", (Standard_Integer (GeomAPI_ProjectPointOnSurf::*)() const) &GeomAPI_ProjectPointOnSurf::NbPoints, "Returns the number of computed orthogonal projection points. Note: if projection fails, NbPoints returns 0.");
cls_GeomAPI_ProjectPointOnSurf.def("Point", (gp_Pnt (GeomAPI_ProjectPointOnSurf::*)(const Standard_Integer) const) &GeomAPI_ProjectPointOnSurf::Point, "Returns the orthogonal projection on the surface. Index is a number of a computed point. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of solution points.", py::arg("Index"));
cls_GeomAPI_ProjectPointOnSurf.def("Parameters", [](GeomAPI_ProjectPointOnSurf &self, const Standard_Integer Index, Standard_Real & U, Standard_Real & V){ self.Parameters(Index, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Returns the parameters (U,V) on the surface of the orthogonal projection. Index is a number of a computed point. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of solution points.", py::arg("Index"), py::arg("U"), py::arg("V"));
cls_GeomAPI_ProjectPointOnSurf.def("Distance", (Standard_Real (GeomAPI_ProjectPointOnSurf::*)(const Standard_Integer) const) &GeomAPI_ProjectPointOnSurf::Distance, "Computes the distance between the point and its orthogonal projection on the surface. Index is a number of a computed point. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of solution points.", py::arg("Index"));
cls_GeomAPI_ProjectPointOnSurf.def("NearestPoint", (gp_Pnt (GeomAPI_ProjectPointOnSurf::*)() const) &GeomAPI_ProjectPointOnSurf::NearestPoint, "Returns the nearest orthogonal projection of the point on the surface. Exceptions StdFail_NotDone if projection fails.");
cls_GeomAPI_ProjectPointOnSurf.def("LowerDistanceParameters", [](GeomAPI_ProjectPointOnSurf &self, Standard_Real & U, Standard_Real & V){ self.LowerDistanceParameters(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Returns the parameters (U,V) on the surface of the nearest computed orthogonal projection of the point. Exceptions StdFail_NotDone if projection fails.", py::arg("U"), py::arg("V"));
cls_GeomAPI_ProjectPointOnSurf.def("LowerDistance", (Standard_Real (GeomAPI_ProjectPointOnSurf::*)() const) &GeomAPI_ProjectPointOnSurf::LowerDistance, "Computes the distance between the point and its nearest orthogonal projection on the surface. Exceptions StdFail_NotDone if projection fails.");
cls_GeomAPI_ProjectPointOnSurf.def("Extrema", (const Extrema_ExtPS & (GeomAPI_ProjectPointOnSurf::*)() const) &GeomAPI_ProjectPointOnSurf::Extrema, "return the algorithmic object from Extrema");


}