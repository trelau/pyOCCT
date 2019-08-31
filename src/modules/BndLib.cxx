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
#include <gp_Lin.hxx>
#include <Standard_TypeDef.hxx>
#include <Bnd_Box.hxx>
#include <gp_Lin2d.hxx>
#include <Bnd_Box2d.hxx>
#include <gp_Circ.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Parab.hxx>
#include <gp_Parab2d.hxx>
#include <gp_Hypr.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <gp_Sphere.hxx>
#include <gp_Torus.hxx>
#include <BndLib_Add3dCurve.hxx>
#include <BndLib_Add2dCurve.hxx>
#include <BndLib_AddSurface.hxx>
#include <BndLib.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Adaptor3d_Surface.hxx>

PYBIND11_MODULE(BndLib, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Adaptor3d");

// CLASS: BNDLIB
py::class_<BndLib> cls_BndLib(mod, "BndLib", "The BndLib package provides functions to add a geometric primitive to a bounding box. Note: these functions work with gp objects, optionally limited by parameter values. If the curves and surfaces provided by the gp package are not explicitly parameterized, they still have an implicit parameterization, similar to that which they infer for the equivalent Geom or Geom2d objects. Add : Package to compute the bounding boxes for elementary objects from gp in 2d and 3d .");

// Methods
// cls_BndLib.def_static("operator new_", (void * (*)(size_t)) &BndLib::operator new, "None", py::arg("theSize"));
// cls_BndLib.def_static("operator delete_", (void (*)(void *)) &BndLib::operator delete, "None", py::arg("theAddress"));
// cls_BndLib.def_static("operator new[]_", (void * (*)(size_t)) &BndLib::operator new[], "None", py::arg("theSize"));
// cls_BndLib.def_static("operator delete[]_", (void (*)(void *)) &BndLib::operator delete[], "None", py::arg("theAddress"));
// cls_BndLib.def_static("operator new_", (void * (*)(size_t, void *)) &BndLib::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BndLib.def_static("operator delete_", (void (*)(void *, void *)) &BndLib::operator delete, "None", py::arg(""), py::arg(""));
cls_BndLib.def_static("Add_", (void (*)(const gp_Lin &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "Bounding box for a surface trimmed or not Adds the segment of the line L limited by the two parameter values P1 and P2, to the bounding box B, and then enlarges B by the tolerance value Tol. Tol is the tolerance value to enlarge the minimun and maximum dimension P1 and P2 may represent infinite values. Exceptions Standard_Failure if P1 and P2 are either two negative infinite real numbers, or two positive infinite real numbers.", py::arg("L"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box2d &)) &BndLib::Add, "None", py::arg("L"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Circ &, const Standard_Real, Bnd_Box &)) &BndLib::Add, "None", py::arg("C"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Circ &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "P2-P1 can be in [0,2*pi]", py::arg("C"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Circ2d &, const Standard_Real, Bnd_Box2d &)) &BndLib::Add, "None", py::arg("C"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Circ2d &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box2d &)) &BndLib::Add, "Adds the circle C, or the arc of the circle C limited by the two parameter values P1 and P2, to the bounding box B, and then enlarges B by the tolerance value Tol. P2-P1 can be in [0,2*pi]", py::arg("C"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Elips &, const Standard_Real, Bnd_Box &)) &BndLib::Add, "None", py::arg("C"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Elips &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "P2-P1 can be in [0,2*pi]", py::arg("C"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Elips2d &, const Standard_Real, Bnd_Box2d &)) &BndLib::Add, "None", py::arg("C"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Elips2d &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box2d &)) &BndLib::Add, "Adds the ellipse E, or the arc of the ellipse E limited by the two parameter values P1 and P2, to the bounding box B, and then enlarges B by the tolerance value Tol. P2-P1 can be in [0,2*pi]", py::arg("C"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Parab &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "None", py::arg("P"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Parab2d &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box2d &)) &BndLib::Add, "Adds the arc of the parabola P limited by the two parameter values P1 and P2, to the bounding box B, and then enlarges B by the tolerance value Tol. P1 and P2 may represent infinite values. Exceptions Standard_Failure if P1 and P2 are either two negative infinite real numbers, or two positive infinite real numbers.", py::arg("P"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Hypr &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "None", py::arg("H"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Hypr2d &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box2d &)) &BndLib::Add, "Adds the arc of the branch of hyperbola H limited by the two parameter values P1 and P2, to the bounding box B, and then enlarges B by the tolerance value Tol. P1 and P2 may represent infinite values. Exceptions Standard_Failure if P1 and P2 are either two negative infinite real numbers, or two positive infinite real numbers.", py::arg("H"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "UMax -UMin can be in [0,2*pi]", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "Adds to the bounding box B, the patch of the cylinder S limited - in the v parametric direction, by the two parameter values VMin and VMax - and optionally in the u parametric direction, by the two parameter values UMin and UMax. B is then enlarged by the tolerance value Tol. VMin and VMax may represent infinite values. Exceptions Standard_Failure if VMin and VMax are either two negative infinite real numbers, or two positive infinite real numbers.", py::arg("S"), py::arg("VMin"), py::arg("VMax"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Cone &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "UMax-UMin can be in [0,2*pi]", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Cone &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "Adds to the bounding box B, the patch of the cone S limited - in the v parametric direction, by the two parameter values VMin and VMax - and optionally in the u parametric direction, by the two parameter values UMin and UMax, B is then enlarged by the tolerance value Tol. VMin and VMax may represent infinite values. Exceptions Standard_Failure if VMin and VMax are either two negative infinite real numbers, or two positive infinite real numbers.", py::arg("S"), py::arg("VMin"), py::arg("VMax"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Sphere &, const Standard_Real, Bnd_Box &)) &BndLib::Add, "None", py::arg("S"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Sphere &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "Adds to the bounding box B the sphere S, or - the patch of the sphere S, limited in the u parametric direction, by the two parameter values UMin and UMax, and in the v parametric direction, by the two parameter values VMin and VMax. B is then enlarged by the tolerance value Tol. UMax-UMin can be in [0,2*pi] VMin,VMax can be [-pi/2,pi/2]", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Torus &, const Standard_Real, Bnd_Box &)) &BndLib::Add, "None", py::arg("P"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Torus &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "Adds to the bounding box B - the torus S, or - the patch of the torus S, limited in the u parametric direction, by the two parameter values UMin and UMax, and in the v parametric direction, by the two parameter values VMin and VMax. B is then enlarged by the tolerance value Tol. UMax-UMin can be in [0,2*pi], VMin,VMax can be [-pi/2,pi/2]", py::arg("P"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Tol"), py::arg("B"));

// CLASS: BNDLIB_ADD2DCURVE
py::class_<BndLib_Add2dCurve> cls_BndLib_Add2dCurve(mod, "BndLib_Add2dCurve", "Computes the bounding box for a curve in 2d . Functions to add a 2D curve to a bounding box. The 2D curve is defined from a Geom2d curve.");

// Methods
// cls_BndLib_Add2dCurve.def_static("operator new_", (void * (*)(size_t)) &BndLib_Add2dCurve::operator new, "None", py::arg("theSize"));
// cls_BndLib_Add2dCurve.def_static("operator delete_", (void (*)(void *)) &BndLib_Add2dCurve::operator delete, "None", py::arg("theAddress"));
// cls_BndLib_Add2dCurve.def_static("operator new[]_", (void * (*)(size_t)) &BndLib_Add2dCurve::operator new[], "None", py::arg("theSize"));
// cls_BndLib_Add2dCurve.def_static("operator delete[]_", (void (*)(void *)) &BndLib_Add2dCurve::operator delete[], "None", py::arg("theAddress"));
// cls_BndLib_Add2dCurve.def_static("operator new_", (void * (*)(size_t, void *)) &BndLib_Add2dCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BndLib_Add2dCurve.def_static("operator delete_", (void (*)(void *, void *)) &BndLib_Add2dCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_BndLib_Add2dCurve.def_static("Add_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, Bnd_Box2d &)) &BndLib_Add2dCurve::Add, "Adds to the bounding box B the curve C B is then enlarged by the tolerance value Tol. Note: depending on the type of curve, one of the following representations of the curve C is used to include it in the bounding box B: - an exact representation if C is built from a line, a circle or a conic curve, - the poles of the curve if C is built from a Bezier curve or a BSpline curve, - if not, the points of an approximation of the curve C. Warning C is an adapted curve, that is, an object which is an interface between: - the services provided by a 2D curve from the package Geom2d - and those required of the curve by the computation algorithm. The adapted curve is created in the following way: Handle(Geom2d_Curve) mycurve = ... ; Geom2dAdaptor_Curve C(mycurve); The bounding box B is then enlarged by adding it: Bnd_Box2d B; // ... Standard_Real Tol = ... ; Add2dCurve::Add ( C, Tol, B ); Exceptions Standard_Failure if the curve is built from: - a Geom_Line, or - a Geom_Parabola, or - a Geom_Hyperbola, and P1 and P2 are either two negative infinite real numbers, or two positive infinite real numbers.", py::arg("C"), py::arg("Tol"), py::arg("B"));
cls_BndLib_Add2dCurve.def_static("Add_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box2d &)) &BndLib_Add2dCurve::Add, "Adds to the bounding box Bthe arc of the curve C limited by the two parameter values P1 and P2. B is then enlarged by the tolerance value Tol. Note: depending on the type of curve, one of the following representations of the curve C is used to include it in the bounding box B: - an exact representation if C is built from a line, a circle or a conic curve, - the poles of the curve if C is built from a Bezier curve or a BSpline curve, - if not, the points of an approximation of the curve C. Warning C is an adapted curve, that is, an object which is an interface between: - the services provided by a 2D curve from the package Geom2d - and those required of the curve by the computation algorithm. The adapted curve is created in the following way: Handle(Geom2d_Curve) mycurve = ... ; Geom2dAdaptor_Curve C(mycurve); The bounding box B is then enlarged by adding it: Bnd_Box2d B; // ... Standard_Real Tol = ... ; Add2dCurve::Add ( C, Tol, B ); Exceptions Standard_Failure if the curve is built from: - a Geom_Line, or - a Geom_Parabola, or - a Geom_Hyperbola, and P1 and P2 are either two negative infinite real numbers, or two positive infinite real numbers.", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"), py::arg("B"));
cls_BndLib_Add2dCurve.def_static("Add_", (void (*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, Bnd_Box2d &)) &BndLib_Add2dCurve::Add, "Adds to the bounding box B the curve C B is then enlarged by the tolerance value Tol. Note: depending on the type of curve, one of the following representations of the curve C is used to include it in the bounding box B: - an exact representation if C is built from a line, a circle or a conic curve, - the poles of the curve if C is built from a Bezier curve or a BSpline curve, - if not, the points of an approximation of the curve C.", py::arg("C"), py::arg("Tol"), py::arg("Box"));
cls_BndLib_Add2dCurve.def_static("Add_", (void (*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box2d &)) &BndLib_Add2dCurve::Add, "Adds to the bounding box B the part of curve C B is then enlarged by the tolerance value Tol. U1, U2 - the parametric range to comute the bounding box; Note: depending on the type of curve, one of the following representations of the curve C is used to include it in the bounding box B: - an exact representation if C is built from a line, a circle or a conic curve, - the poles of the curve if C is built from a Bezier curve or a BSpline curve, - if not, the points of an approximation of the curve C.", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"), py::arg("B"));
cls_BndLib_Add2dCurve.def_static("AddOptimal_", (void (*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box2d &)) &BndLib_Add2dCurve::AddOptimal, "Adds to the bounding box B the part of curve C B is then enlarged by the tolerance value Tol. U1, U2 - the parametric range to comute the bounding box; Note: depending on the type of curve, one of the following algorithms is used to include it in the bounding box B: - an exact analytical if C is built from a line, a circle or a conic curve, - numerical calculation of bounding box sizes, based on minimization algorithm, for other types of curve If Tol = < Precision::PConfusion(), Precision::PConfusion is used as tolerance for calculation", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"), py::arg("B"));

// CLASS: BNDLIB_ADD3DCURVE
py::class_<BndLib_Add3dCurve> cls_BndLib_Add3dCurve(mod, "BndLib_Add3dCurve", "Computes the bounding box for a curve in 3d. Functions to add a 3D curve to a bounding box. The 3D curve is defined from a Geom curve.");

// Methods
// cls_BndLib_Add3dCurve.def_static("operator new_", (void * (*)(size_t)) &BndLib_Add3dCurve::operator new, "None", py::arg("theSize"));
// cls_BndLib_Add3dCurve.def_static("operator delete_", (void (*)(void *)) &BndLib_Add3dCurve::operator delete, "None", py::arg("theAddress"));
// cls_BndLib_Add3dCurve.def_static("operator new[]_", (void * (*)(size_t)) &BndLib_Add3dCurve::operator new[], "None", py::arg("theSize"));
// cls_BndLib_Add3dCurve.def_static("operator delete[]_", (void (*)(void *)) &BndLib_Add3dCurve::operator delete[], "None", py::arg("theAddress"));
// cls_BndLib_Add3dCurve.def_static("operator new_", (void * (*)(size_t, void *)) &BndLib_Add3dCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BndLib_Add3dCurve.def_static("operator delete_", (void (*)(void *, void *)) &BndLib_Add3dCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_BndLib_Add3dCurve.def_static("Add_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, Bnd_Box &)) &BndLib_Add3dCurve::Add, "Adds to the bounding box B the curve C B is then enlarged by the tolerance value Tol. Note: depending on the type of curve, one of the following representations of the curve C is used to include it in the bounding box B: - an exact representation if C is built from a line, a circle or a conic curve, - the poles of the curve if C is built from a Bezier curve or a BSpline curve, if not, the points of an approximation of the curve C. Warning C is an adapted curve, that is, an object which is an interface between: - the services provided by a 3D curve from the package Geom - and those required of the curve by the computation algorithm. The adapted curve is created in the following way: Handle(Geom_Curve) mycurve = ... ; GeomAdaptor_Curve C(mycurve); The bounding box B is then enlarged by adding it: Bnd_Box B; // ... Standard_Real Tol = ... ; Add3dCurve::Add ( C, Tol, B ); Exceptions Standard_Failure if the curve is built from: - a Geom_Line, or - a Geom_Parabola, or - a Geom_Hyperbola, and P1 and P2 are either two negative infinite real numbers, or two positive infinite real numbers.", py::arg("C"), py::arg("Tol"), py::arg("B"));
cls_BndLib_Add3dCurve.def_static("Add_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib_Add3dCurve::Add, "Adds to the bounding box B the curve C the arc of the curve C limited by the two parameter values P1 and P2. Note: depending on the type of curve, one of the following representations of the curve C is used to include it in the bounding box B: - an exact representation if C is built from a line, a circle or a conic curve, - the poles of the curve if C is built from a Bezier curve or a BSpline curve, if not, the points of an approximation of the curve C. Warning C is an adapted curve, that is, an object which is an interface between: - the services provided by a 3D curve from the package Geom - and those required of the curve by the computation algorithm. The adapted curve is created in the following way: Handle(Geom_Curve) mycurve = ... ; GeomAdaptor_Curve C(mycurve); The bounding box B is then enlarged by adding it: Bnd_Box B; // ... Standard_Real Tol = ... ; Add3dCurve::Add ( C, Tol, B ); Exceptions Standard_Failure if the curve is built from: - a Geom_Line, or - a Geom_Parabola, or - a Geom_Hyperbola, and P1 and P2 are either two negative infinite real numbers, or two positive infinite real numbers.", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"), py::arg("B"));
cls_BndLib_Add3dCurve.def_static("AddOptimal_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, Bnd_Box &)) &BndLib_Add3dCurve::AddOptimal, "Adds to the bounding box B the curve C These methods use more precise algorithms for building bnd box then methods Add(...)", py::arg("C"), py::arg("Tol"), py::arg("B"));
cls_BndLib_Add3dCurve.def_static("AddOptimal_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib_Add3dCurve::AddOptimal, "None", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"), py::arg("B"));
cls_BndLib_Add3dCurve.def_static("AddGenCurv_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib_Add3dCurve::AddGenCurv, "Adds to the bounding box B the curve C using numerical minimization algorithms This method is used in AddOptimal for not analytical curves. if Tol < Precision::Confusion(), Precision:;Confusion is used as computation tolerance", py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("Tol"), py::arg("B"));

// CLASS: BNDLIB_ADDSURFACE
py::class_<BndLib_AddSurface> cls_BndLib_AddSurface(mod, "BndLib_AddSurface", "computes the box from a surface Functions to add a surface to a bounding box. The surface is defined from a Geom surface.");

// Methods
// cls_BndLib_AddSurface.def_static("operator new_", (void * (*)(size_t)) &BndLib_AddSurface::operator new, "None", py::arg("theSize"));
// cls_BndLib_AddSurface.def_static("operator delete_", (void (*)(void *)) &BndLib_AddSurface::operator delete, "None", py::arg("theAddress"));
// cls_BndLib_AddSurface.def_static("operator new[]_", (void * (*)(size_t)) &BndLib_AddSurface::operator new[], "None", py::arg("theSize"));
// cls_BndLib_AddSurface.def_static("operator delete[]_", (void (*)(void *)) &BndLib_AddSurface::operator delete[], "None", py::arg("theAddress"));
// cls_BndLib_AddSurface.def_static("operator new_", (void * (*)(size_t, void *)) &BndLib_AddSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BndLib_AddSurface.def_static("operator delete_", (void (*)(void *, void *)) &BndLib_AddSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_BndLib_AddSurface.def_static("Add_", (void (*)(const Adaptor3d_Surface &, const Standard_Real, Bnd_Box &)) &BndLib_AddSurface::Add, "Adds to the bounding box B the surface S B is then enlarged by the tolerance value Tol. Note: depending on the type of curve, one of the following representations of the surface S is used to include it in the bounding box B: - an exact representation if S is built from a plane, a cylinder, a cone, a sphere or a torus, - the poles of the surface if S is built from a Bezier surface or a BSpline surface, - the points of an approximation of the surface S in cases other than offset surfaces; - in the case of an offset surface, the basis surface is first included according to the previous rules; then the bounding box is enlarged by the offset value. Warning Do not use these functions to add a non-finite surface to the bounding box B. If UMin, UMax, VMin or VMax is an infinite value B will become WholeSpace. S is an adapted surface, that is, an object which is an interface between: - the services provided by a surface from the package Geom - and those required of the surface by the computation algorithm. The adapted surface is created in the following way: Handle(Geom_Surface) mysurface = ... ; GeomAdaptor_Surface S(mysurface); The bounding box B is then enlarged by adding this surface: Bnd_Box B; // ... Standard_Real Tol = ... ; AddSurface::Add ( S, Tol, B );", py::arg("S"), py::arg("Tol"), py::arg("B"));
cls_BndLib_AddSurface.def_static("Add_", (void (*)(const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib_AddSurface::Add, "Adds to the bounding box B the surface S the patch of the surface S limited in the u parametric direction by the two parameter values UMin, UMax, and in the v parametric direction by the two parameter values VMin, VMax. Note: depending on the type of curve, one of the following representations of the surface S is used to include it in the bounding box B: - an exact representation if S is built from a plane, a cylinder, a cone, a sphere or a torus, - the poles of the surface if S is built from a Bezier surface or a BSpline surface, - the points of an approximation of the surface S in cases other than offset surfaces; - in the case of an offset surface, the basis surface is first included according to the previous rules; then the bounding box is enlarged by the offset value. Warning Do not use these functions to add a non-finite surface to the bounding box B. If UMin, UMax, VMin or VMax is an infinite value B will become WholeSpace. S is an adapted surface, that is, an object which is an interface between: - the services provided by a surface from the package Geom - and those required of the surface by the computation algorithm. The adapted surface is created in the following way: Handle(Geom_Surface) mysurface = ... ; GeomAdaptor_Surface S(mysurface); The bounding box B is then enlarged by adding this surface: Bnd_Box B; // ... Standard_Real Tol = ... ; AddSurface::Add ( S, Tol, B );", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Tol"), py::arg("B"));
cls_BndLib_AddSurface.def_static("AddOptimal_", (void (*)(const Adaptor3d_Surface &, const Standard_Real, Bnd_Box &)) &BndLib_AddSurface::AddOptimal, "Adds the surface S to the bounding box B. This algorith builds precise bounding box", py::arg("S"), py::arg("Tol"), py::arg("B"));
cls_BndLib_AddSurface.def_static("AddOptimal_", (void (*)(const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib_AddSurface::AddOptimal, "None", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Tol"), py::arg("B"));
cls_BndLib_AddSurface.def_static("AddGenSurf_", (void (*)(const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib_AddSurface::AddGenSurf, "Adds to the bounding box B the surface S using numerical minimization algorithms This method is used in AddOptimal for not analytical surfaces and torus. if Tol < Precision::Confusion(), Precision::Confusion is used as computation tolerance", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Tol"), py::arg("B"));


}
