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
#include <AppParCurves_Constraint.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <AppParCurves_MultiPoint.hxx>
#include <NCollection_Array1.hxx>
#include <AppParCurves_Array1OfMultiPoint.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Std.hxx>
#include <AppParCurves_HArray1OfMultiPoint.hxx>
#include <Standard_Type.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <AppParCurves_MultiCurve.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <AppParCurves_MultiBSpCurve.hxx>
#include <AppParCurves_ConstraintCouple.hxx>
#include <AppParCurves_Array1OfConstraintCouple.hxx>
#include <AppParCurves_HArray1OfConstraintCouple.hxx>
#include <NCollection_Sequence.hxx>
#include <AppParCurves_SequenceOfMultiCurve.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <math_IntegerVector.hxx>
#include <AppParCurves.hxx>
#include <AppParCurves_Array1OfMultiBSpCurve.hxx>
#include <AppParCurves_Array1OfMultiCurve.hxx>
#include <AppParCurves_HArray1OfMultiBSpCurve.hxx>
#include <AppParCurves_HArray1OfMultiCurve.hxx>
#include <AppParCurves_SequenceOfMultiBSpCurve.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(AppParCurves, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.math");

// ENUM: APPPARCURVES_CONSTRAINT
py::enum_<AppParCurves_Constraint>(mod, "AppParCurves_Constraint", "- NoConstraint: this point has no constraints. - PassPoint: the approximation curve passes through this point. - TangencyPoint: this point has a tangency constraint. - CurvaturePoint: this point has a curvature constraint.")
	.value("AppParCurves_NoConstraint", AppParCurves_Constraint::AppParCurves_NoConstraint)
	.value("AppParCurves_PassPoint", AppParCurves_Constraint::AppParCurves_PassPoint)
	.value("AppParCurves_TangencyPoint", AppParCurves_Constraint::AppParCurves_TangencyPoint)
	.value("AppParCurves_CurvaturePoint", AppParCurves_Constraint::AppParCurves_CurvaturePoint)
	.export_values();


// CLASS: APPPARCURVES_MULTIPOINT
py::class_<AppParCurves_MultiPoint> cls_AppParCurves_MultiPoint(mod, "AppParCurves_MultiPoint", "This class describes Points composing a MultiPoint. These points can be 2D or 3D. The user must first give the 3D Points and then the 2D Points. They are Poles of a Bezier Curve. This class is used either to define data input or results when performing the approximation of several lines in parallel.");

// Constructors
cls_AppParCurves_MultiPoint.def(py::init<>());
cls_AppParCurves_MultiPoint.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("NbPoints"), py::arg("NbPoints2d"));
cls_AppParCurves_MultiPoint.def(py::init<const TColgp_Array1OfPnt &>(), py::arg("tabP"));
cls_AppParCurves_MultiPoint.def(py::init<const TColgp_Array1OfPnt2d &>(), py::arg("tabP2d"));
cls_AppParCurves_MultiPoint.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt2d &>(), py::arg("tabP"), py::arg("tabP2d"));

// Methods
// cls_AppParCurves_MultiPoint.def_static("operator new_", (void * (*)(size_t)) &AppParCurves_MultiPoint::operator new, "None", py::arg("theSize"));
// cls_AppParCurves_MultiPoint.def_static("operator delete_", (void (*)(void *)) &AppParCurves_MultiPoint::operator delete, "None", py::arg("theAddress"));
// cls_AppParCurves_MultiPoint.def_static("operator new[]_", (void * (*)(size_t)) &AppParCurves_MultiPoint::operator new[], "None", py::arg("theSize"));
// cls_AppParCurves_MultiPoint.def_static("operator delete[]_", (void (*)(void *)) &AppParCurves_MultiPoint::operator delete[], "None", py::arg("theAddress"));
// cls_AppParCurves_MultiPoint.def_static("operator new_", (void * (*)(size_t, void *)) &AppParCurves_MultiPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppParCurves_MultiPoint.def_static("operator delete_", (void (*)(void *, void *)) &AppParCurves_MultiPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_AppParCurves_MultiPoint.def("SetPoint", (void (AppParCurves_MultiPoint::*)(const Standard_Integer, const gp_Pnt &)) &AppParCurves_MultiPoint::SetPoint, "the 3d Point of range Index of this MultiPoint is set to <Point>. An exception is raised if Index < 0 or Index > number of 3d Points.", py::arg("Index"), py::arg("Point"));
cls_AppParCurves_MultiPoint.def("Point", (const gp_Pnt & (AppParCurves_MultiPoint::*)(const Standard_Integer) const) &AppParCurves_MultiPoint::Point, "returns the 3d Point of range Index. An exception is raised if Index < 0 or Index < number of 3d Points.", py::arg("Index"));
cls_AppParCurves_MultiPoint.def("SetPoint2d", (void (AppParCurves_MultiPoint::*)(const Standard_Integer, const gp_Pnt2d &)) &AppParCurves_MultiPoint::SetPoint2d, "The 2d Point of range Index is set to <Point>. An exception is raised if Index > 3d Points or Index > total number of Points.", py::arg("Index"), py::arg("Point"));
cls_AppParCurves_MultiPoint.def("Point2d", (const gp_Pnt2d & (AppParCurves_MultiPoint::*)(const Standard_Integer) const) &AppParCurves_MultiPoint::Point2d, "returns the 2d Point of range Index. An exception is raised if index <= number of 3d Points or Index > total number of Points.", py::arg("Index"));
cls_AppParCurves_MultiPoint.def("Dimension", (Standard_Integer (AppParCurves_MultiPoint::*)(const Standard_Integer) const) &AppParCurves_MultiPoint::Dimension, "returns the dimension of the point of range Index. An exception is raised if Index <0 or Index > NbCurves.", py::arg("Index"));
cls_AppParCurves_MultiPoint.def("NbPoints", (Standard_Integer (AppParCurves_MultiPoint::*)() const) &AppParCurves_MultiPoint::NbPoints, "returns the number of points of dimension 3D.");
cls_AppParCurves_MultiPoint.def("NbPoints2d", (Standard_Integer (AppParCurves_MultiPoint::*)() const) &AppParCurves_MultiPoint::NbPoints2d, "returns the number of points of dimension 2D.");
cls_AppParCurves_MultiPoint.def("Transform", (void (AppParCurves_MultiPoint::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AppParCurves_MultiPoint::Transform, "Applies a transformation to the curve of range <CuIndex>. newx = x + dx*oldx newy = y + dy*oldy for all points of the curve. newz = z + dz*oldz", py::arg("CuIndex"), py::arg("x"), py::arg("dx"), py::arg("y"), py::arg("dy"), py::arg("z"), py::arg("dz"));
cls_AppParCurves_MultiPoint.def("Transform2d", (void (AppParCurves_MultiPoint::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AppParCurves_MultiPoint::Transform2d, "Applies a transformation to the Curve of range <CuIndex>. newx = x + dx*oldx newy = y + dy*oldy for all points of the curve.", py::arg("CuIndex"), py::arg("x"), py::arg("dx"), py::arg("y"), py::arg("dy"));
cls_AppParCurves_MultiPoint.def("Dump", (void (AppParCurves_MultiPoint::*)(Standard_OStream &) const) &AppParCurves_MultiPoint::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// TYPEDEF: APPPARCURVES_ARRAY1OFMULTIPOINT
bind_NCollection_Array1<AppParCurves_MultiPoint>(mod, "AppParCurves_Array1OfMultiPoint", py::module_local(false));

// CLASS: APPPARCURVES_HARRAY1OFMULTIPOINT
py::class_<AppParCurves_HArray1OfMultiPoint, opencascade::handle<AppParCurves_HArray1OfMultiPoint>, Standard_Transient> cls_AppParCurves_HArray1OfMultiPoint(mod, "AppParCurves_HArray1OfMultiPoint", "None", py::multiple_inheritance());

// Constructors
cls_AppParCurves_HArray1OfMultiPoint.def(py::init<>());
cls_AppParCurves_HArray1OfMultiPoint.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_AppParCurves_HArray1OfMultiPoint.def(py::init<const Standard_Integer, const Standard_Integer, const AppParCurves_Array1OfMultiPoint::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_AppParCurves_HArray1OfMultiPoint.def(py::init<const AppParCurves_Array1OfMultiPoint &>(), py::arg("theOther"));

// Methods
// cls_AppParCurves_HArray1OfMultiPoint.def_static("operator new_", (void * (*)(size_t)) &AppParCurves_HArray1OfMultiPoint::operator new, "None", py::arg("theSize"));
// cls_AppParCurves_HArray1OfMultiPoint.def_static("operator delete_", (void (*)(void *)) &AppParCurves_HArray1OfMultiPoint::operator delete, "None", py::arg("theAddress"));
// cls_AppParCurves_HArray1OfMultiPoint.def_static("operator new[]_", (void * (*)(size_t)) &AppParCurves_HArray1OfMultiPoint::operator new[], "None", py::arg("theSize"));
// cls_AppParCurves_HArray1OfMultiPoint.def_static("operator delete[]_", (void (*)(void *)) &AppParCurves_HArray1OfMultiPoint::operator delete[], "None", py::arg("theAddress"));
// cls_AppParCurves_HArray1OfMultiPoint.def_static("operator new_", (void * (*)(size_t, void *)) &AppParCurves_HArray1OfMultiPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppParCurves_HArray1OfMultiPoint.def_static("operator delete_", (void (*)(void *, void *)) &AppParCurves_HArray1OfMultiPoint::operator delete, "None", py::arg(""), py::arg(""));
// cls_AppParCurves_HArray1OfMultiPoint.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &AppParCurves_HArray1OfMultiPoint::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_AppParCurves_HArray1OfMultiPoint.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &AppParCurves_HArray1OfMultiPoint::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_AppParCurves_HArray1OfMultiPoint.def("Array1", (const AppParCurves_Array1OfMultiPoint & (AppParCurves_HArray1OfMultiPoint::*)() const) &AppParCurves_HArray1OfMultiPoint::Array1, "None");
cls_AppParCurves_HArray1OfMultiPoint.def("ChangeArray1", (AppParCurves_Array1OfMultiPoint & (AppParCurves_HArray1OfMultiPoint::*)()) &AppParCurves_HArray1OfMultiPoint::ChangeArray1, "None");
cls_AppParCurves_HArray1OfMultiPoint.def_static("get_type_name_", (const char * (*)()) &AppParCurves_HArray1OfMultiPoint::get_type_name, "None");
cls_AppParCurves_HArray1OfMultiPoint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AppParCurves_HArray1OfMultiPoint::get_type_descriptor, "None");
cls_AppParCurves_HArray1OfMultiPoint.def("DynamicType", (const opencascade::handle<Standard_Type> & (AppParCurves_HArray1OfMultiPoint::*)() const) &AppParCurves_HArray1OfMultiPoint::DynamicType, "None");

// CLASS: APPPARCURVES_MULTICURVE
py::class_<AppParCurves_MultiCurve> cls_AppParCurves_MultiCurve(mod, "AppParCurves_MultiCurve", "This class describes a MultiCurve approximating a Multiline. As a Multiline is a set of n lines, a MultiCurve is a set of n curves. These curves are Bezier curves. A MultiCurve is composed of m MultiPoint. The approximating degree of these n curves is the same for each one.");

// Constructors
cls_AppParCurves_MultiCurve.def(py::init<>());
cls_AppParCurves_MultiCurve.def(py::init<const Standard_Integer>(), py::arg("NbPol"));
cls_AppParCurves_MultiCurve.def(py::init<const AppParCurves_Array1OfMultiPoint &>(), py::arg("tabMU"));

// Methods
// cls_AppParCurves_MultiCurve.def_static("operator new_", (void * (*)(size_t)) &AppParCurves_MultiCurve::operator new, "None", py::arg("theSize"));
// cls_AppParCurves_MultiCurve.def_static("operator delete_", (void (*)(void *)) &AppParCurves_MultiCurve::operator delete, "None", py::arg("theAddress"));
// cls_AppParCurves_MultiCurve.def_static("operator new[]_", (void * (*)(size_t)) &AppParCurves_MultiCurve::operator new[], "None", py::arg("theSize"));
// cls_AppParCurves_MultiCurve.def_static("operator delete[]_", (void (*)(void *)) &AppParCurves_MultiCurve::operator delete[], "None", py::arg("theAddress"));
// cls_AppParCurves_MultiCurve.def_static("operator new_", (void * (*)(size_t, void *)) &AppParCurves_MultiCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppParCurves_MultiCurve.def_static("operator delete_", (void (*)(void *, void *)) &AppParCurves_MultiCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_AppParCurves_MultiCurve.def("SetNbPoles", (void (AppParCurves_MultiCurve::*)(const Standard_Integer)) &AppParCurves_MultiCurve::SetNbPoles, "The number of poles of the MultiCurve will be set to <nbPoles>.", py::arg("nbPoles"));
cls_AppParCurves_MultiCurve.def("SetValue", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const AppParCurves_MultiPoint &)) &AppParCurves_MultiCurve::SetValue, "sets the MultiPoint of range Index to the value <MPoint>. An exception is raised if Index <0 or Index >NbMPoint.", py::arg("Index"), py::arg("MPoint"));
cls_AppParCurves_MultiCurve.def("NbCurves", (Standard_Integer (AppParCurves_MultiCurve::*)() const) &AppParCurves_MultiCurve::NbCurves, "Returns the number of curves resulting from the approximation of a MultiLine.");
cls_AppParCurves_MultiCurve.def("NbPoles", (Standard_Integer (AppParCurves_MultiCurve::*)() const) &AppParCurves_MultiCurve::NbPoles, "Returns the number of poles on curves resulting from the approximation of a MultiLine.");
cls_AppParCurves_MultiCurve.def("Degree", (Standard_Integer (AppParCurves_MultiCurve::*)() const) &AppParCurves_MultiCurve::Degree, "returns the degree of the curves.");
cls_AppParCurves_MultiCurve.def("Dimension", (Standard_Integer (AppParCurves_MultiCurve::*)(const Standard_Integer) const) &AppParCurves_MultiCurve::Dimension, "returns the dimension of the CuIndex curve. An exception is raised if CuIndex<0 or CuIndex>NbCurves.", py::arg("CuIndex"));
cls_AppParCurves_MultiCurve.def("Curve", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, TColgp_Array1OfPnt &) const) &AppParCurves_MultiCurve::Curve, "returns the Pole array of the curve of range CuIndex. An exception is raised if the dimension of the curve is 2d.", py::arg("CuIndex"), py::arg("TabPnt"));
cls_AppParCurves_MultiCurve.def("Curve", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, TColgp_Array1OfPnt2d &) const) &AppParCurves_MultiCurve::Curve, "returns the Pole array of the curve of range CuIndex. An exception is raised if the dimension of the curve is 3d.", py::arg("CuIndex"), py::arg("TabPnt"));
cls_AppParCurves_MultiCurve.def("Value", (const AppParCurves_MultiPoint & (AppParCurves_MultiCurve::*)(const Standard_Integer) const) &AppParCurves_MultiCurve::Value, "returns the Index MultiPoint. An exception is raised if Index <0 or Index >Degree+1.", py::arg("Index"));
cls_AppParCurves_MultiCurve.def("Pole", (const gp_Pnt & (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Integer) const) &AppParCurves_MultiCurve::Pole, "returns the Nieme pole of the CuIndex curve. the curve must be a 3D curve.", py::arg("CuIndex"), py::arg("Nieme"));
cls_AppParCurves_MultiCurve.def("Pole2d", (const gp_Pnt2d & (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Integer) const) &AppParCurves_MultiCurve::Pole2d, "returns the Nieme pole of the CuIndex curve. the curve must be a 2D curve.", py::arg("CuIndex"), py::arg("Nieme"));
cls_AppParCurves_MultiCurve.def("Transform", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AppParCurves_MultiCurve::Transform, "Applies a transformation to the curve of range <CuIndex>. newx = x + dx*oldx newy = y + dy*oldy for all points of the curve. newz = z + dz*oldz", py::arg("CuIndex"), py::arg("x"), py::arg("dx"), py::arg("y"), py::arg("dy"), py::arg("z"), py::arg("dz"));
cls_AppParCurves_MultiCurve.def("Transform2d", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AppParCurves_MultiCurve::Transform2d, "Applies a transformation to the Curve of range <CuIndex>. newx = x + dx*oldx newy = y + dy*oldy for all points of the curve.", py::arg("CuIndex"), py::arg("x"), py::arg("dx"), py::arg("y"), py::arg("dy"));
cls_AppParCurves_MultiCurve.def("Value", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt &) const) &AppParCurves_MultiCurve::Value, "returns the value of the point with a parameter U on the Bezier curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 2d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"));
cls_AppParCurves_MultiCurve.def("Value", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt2d &) const) &AppParCurves_MultiCurve::Value, "returns the value of the point with a parameter U on the Bezier curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 3d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"));
cls_AppParCurves_MultiCurve.def("D1", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt &, gp_Vec &) const) &AppParCurves_MultiCurve::D1, "returns the value of the point with a parameter U on the Bezier curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 3d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"));
cls_AppParCurves_MultiCurve.def("D1", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &AppParCurves_MultiCurve::D1, "returns the value of the point with a parameter U on the Bezier curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 2d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"));
cls_AppParCurves_MultiCurve.def("D2", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &AppParCurves_MultiCurve::D2, "returns the value of the point with a parameter U on the Bezier curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 3d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"), py::arg("V2"));
cls_AppParCurves_MultiCurve.def("D2", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &AppParCurves_MultiCurve::D2, "returns the value of the point with a parameter U on the Bezier curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 2d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"), py::arg("V2"));
cls_AppParCurves_MultiCurve.def("Dump", (void (AppParCurves_MultiCurve::*)(Standard_OStream &) const) &AppParCurves_MultiCurve::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// CLASS: APPPARCURVES_MULTIBSPCURVE
py::class_<AppParCurves_MultiBSpCurve, AppParCurves_MultiCurve> cls_AppParCurves_MultiBSpCurve(mod, "AppParCurves_MultiBSpCurve", "This class describes a MultiBSpCurve approximating a Multiline. Just as a Multiline is a set of a given number of lines, a MultiBSpCurve is a set of a specified number of bsplines defined by: - A specified number of MultiPoints - the poles of a specified number of curves - The degree of approximation identical for each of the specified number of curves.");

// Constructors
cls_AppParCurves_MultiBSpCurve.def(py::init<>());
cls_AppParCurves_MultiBSpCurve.def(py::init<const Standard_Integer>(), py::arg("NbPol"));
cls_AppParCurves_MultiBSpCurve.def(py::init<const AppParCurves_Array1OfMultiPoint &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &>(), py::arg("tabMU"), py::arg("Knots"), py::arg("Mults"));
cls_AppParCurves_MultiBSpCurve.def(py::init<const AppParCurves_MultiCurve &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &>(), py::arg("SC"), py::arg("Knots"), py::arg("Mults"));

// Methods
// cls_AppParCurves_MultiBSpCurve.def_static("operator new_", (void * (*)(size_t)) &AppParCurves_MultiBSpCurve::operator new, "None", py::arg("theSize"));
// cls_AppParCurves_MultiBSpCurve.def_static("operator delete_", (void (*)(void *)) &AppParCurves_MultiBSpCurve::operator delete, "None", py::arg("theAddress"));
// cls_AppParCurves_MultiBSpCurve.def_static("operator new[]_", (void * (*)(size_t)) &AppParCurves_MultiBSpCurve::operator new[], "None", py::arg("theSize"));
// cls_AppParCurves_MultiBSpCurve.def_static("operator delete[]_", (void (*)(void *)) &AppParCurves_MultiBSpCurve::operator delete[], "None", py::arg("theAddress"));
// cls_AppParCurves_MultiBSpCurve.def_static("operator new_", (void * (*)(size_t, void *)) &AppParCurves_MultiBSpCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppParCurves_MultiBSpCurve.def_static("operator delete_", (void (*)(void *, void *)) &AppParCurves_MultiBSpCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_AppParCurves_MultiBSpCurve.def("SetKnots", (void (AppParCurves_MultiBSpCurve::*)(const TColStd_Array1OfReal &)) &AppParCurves_MultiBSpCurve::SetKnots, "Knots of the multiBSpCurve are assigned to <theknots>.", py::arg("theKnots"));
cls_AppParCurves_MultiBSpCurve.def("SetMultiplicities", (void (AppParCurves_MultiBSpCurve::*)(const TColStd_Array1OfInteger &)) &AppParCurves_MultiBSpCurve::SetMultiplicities, "Multiplicities of the multiBSpCurve are assigned to <theMults>.", py::arg("theMults"));
cls_AppParCurves_MultiBSpCurve.def("Knots", (const TColStd_Array1OfReal & (AppParCurves_MultiBSpCurve::*)() const) &AppParCurves_MultiBSpCurve::Knots, "Returns an array of Reals containing the multiplicities of curves resulting from the approximation.");
cls_AppParCurves_MultiBSpCurve.def("Multiplicities", (const TColStd_Array1OfInteger & (AppParCurves_MultiBSpCurve::*)() const) &AppParCurves_MultiBSpCurve::Multiplicities, "Returns an array of Reals containing the multiplicities of curves resulting from the approximation.");
cls_AppParCurves_MultiBSpCurve.def("Degree", (Standard_Integer (AppParCurves_MultiBSpCurve::*)() const) &AppParCurves_MultiBSpCurve::Degree, "returns the degree of the curve(s).");
cls_AppParCurves_MultiBSpCurve.def("Value", (void (AppParCurves_MultiBSpCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt &) const) &AppParCurves_MultiBSpCurve::Value, "returns the value of the point with a parameter U on the BSpline curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 2d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"));
cls_AppParCurves_MultiBSpCurve.def("Value", (void (AppParCurves_MultiBSpCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt2d &) const) &AppParCurves_MultiBSpCurve::Value, "returns the value of the point with a parameter U on the BSpline curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 3d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"));
cls_AppParCurves_MultiBSpCurve.def("D1", (void (AppParCurves_MultiBSpCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt &, gp_Vec &) const) &AppParCurves_MultiBSpCurve::D1, "returns the value of the point with a parameter U on the BSpline curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 3d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"));
cls_AppParCurves_MultiBSpCurve.def("D1", (void (AppParCurves_MultiBSpCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &AppParCurves_MultiBSpCurve::D1, "returns the value of the point with a parameter U on the BSpline curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 2d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"));
cls_AppParCurves_MultiBSpCurve.def("D2", (void (AppParCurves_MultiBSpCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &AppParCurves_MultiBSpCurve::D2, "returns the value of the point with a parameter U on the BSpline curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 3d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"), py::arg("V2"));
cls_AppParCurves_MultiBSpCurve.def("D2", (void (AppParCurves_MultiBSpCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &AppParCurves_MultiBSpCurve::D2, "returns the value of the point with a parameter U on the BSpline curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 2d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"), py::arg("V2"));
cls_AppParCurves_MultiBSpCurve.def("Dump", (void (AppParCurves_MultiBSpCurve::*)(Standard_OStream &) const) &AppParCurves_MultiBSpCurve::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// CLASS: APPPARCURVES_CONSTRAINTCOUPLE
py::class_<AppParCurves_ConstraintCouple> cls_AppParCurves_ConstraintCouple(mod, "AppParCurves_ConstraintCouple", "associates an index and a constraint for an object. This couple is used by AppDef_TheVariational when performing approximations.");

// Constructors
cls_AppParCurves_ConstraintCouple.def(py::init<>());
cls_AppParCurves_ConstraintCouple.def(py::init<const Standard_Integer, const AppParCurves_Constraint>(), py::arg("TheIndex"), py::arg("Cons"));

// Methods
// cls_AppParCurves_ConstraintCouple.def_static("operator new_", (void * (*)(size_t)) &AppParCurves_ConstraintCouple::operator new, "None", py::arg("theSize"));
// cls_AppParCurves_ConstraintCouple.def_static("operator delete_", (void (*)(void *)) &AppParCurves_ConstraintCouple::operator delete, "None", py::arg("theAddress"));
// cls_AppParCurves_ConstraintCouple.def_static("operator new[]_", (void * (*)(size_t)) &AppParCurves_ConstraintCouple::operator new[], "None", py::arg("theSize"));
// cls_AppParCurves_ConstraintCouple.def_static("operator delete[]_", (void (*)(void *)) &AppParCurves_ConstraintCouple::operator delete[], "None", py::arg("theAddress"));
// cls_AppParCurves_ConstraintCouple.def_static("operator new_", (void * (*)(size_t, void *)) &AppParCurves_ConstraintCouple::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppParCurves_ConstraintCouple.def_static("operator delete_", (void (*)(void *, void *)) &AppParCurves_ConstraintCouple::operator delete, "None", py::arg(""), py::arg(""));
cls_AppParCurves_ConstraintCouple.def("Index", (Standard_Integer (AppParCurves_ConstraintCouple::*)() const) &AppParCurves_ConstraintCouple::Index, "returns the index of the constraint object.");
cls_AppParCurves_ConstraintCouple.def("Constraint", (AppParCurves_Constraint (AppParCurves_ConstraintCouple::*)() const) &AppParCurves_ConstraintCouple::Constraint, "returns the constraint of the object.");
cls_AppParCurves_ConstraintCouple.def("SetIndex", (void (AppParCurves_ConstraintCouple::*)(const Standard_Integer)) &AppParCurves_ConstraintCouple::SetIndex, "Changes the index of the constraint object.", py::arg("TheIndex"));
cls_AppParCurves_ConstraintCouple.def("SetConstraint", (void (AppParCurves_ConstraintCouple::*)(const AppParCurves_Constraint)) &AppParCurves_ConstraintCouple::SetConstraint, "Changes the constraint of the object.", py::arg("Cons"));

// TYPEDEF: APPPARCURVES_ARRAY1OFCONSTRAINTCOUPLE
bind_NCollection_Array1<AppParCurves_ConstraintCouple>(mod, "AppParCurves_Array1OfConstraintCouple", py::module_local(false));

// CLASS: APPPARCURVES_HARRAY1OFCONSTRAINTCOUPLE
py::class_<AppParCurves_HArray1OfConstraintCouple, opencascade::handle<AppParCurves_HArray1OfConstraintCouple>, Standard_Transient> cls_AppParCurves_HArray1OfConstraintCouple(mod, "AppParCurves_HArray1OfConstraintCouple", "None", py::multiple_inheritance());

// Constructors
cls_AppParCurves_HArray1OfConstraintCouple.def(py::init<>());
cls_AppParCurves_HArray1OfConstraintCouple.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_AppParCurves_HArray1OfConstraintCouple.def(py::init<const Standard_Integer, const Standard_Integer, const AppParCurves_Array1OfConstraintCouple::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_AppParCurves_HArray1OfConstraintCouple.def(py::init<const AppParCurves_Array1OfConstraintCouple &>(), py::arg("theOther"));

// Methods
// cls_AppParCurves_HArray1OfConstraintCouple.def_static("operator new_", (void * (*)(size_t)) &AppParCurves_HArray1OfConstraintCouple::operator new, "None", py::arg("theSize"));
// cls_AppParCurves_HArray1OfConstraintCouple.def_static("operator delete_", (void (*)(void *)) &AppParCurves_HArray1OfConstraintCouple::operator delete, "None", py::arg("theAddress"));
// cls_AppParCurves_HArray1OfConstraintCouple.def_static("operator new[]_", (void * (*)(size_t)) &AppParCurves_HArray1OfConstraintCouple::operator new[], "None", py::arg("theSize"));
// cls_AppParCurves_HArray1OfConstraintCouple.def_static("operator delete[]_", (void (*)(void *)) &AppParCurves_HArray1OfConstraintCouple::operator delete[], "None", py::arg("theAddress"));
// cls_AppParCurves_HArray1OfConstraintCouple.def_static("operator new_", (void * (*)(size_t, void *)) &AppParCurves_HArray1OfConstraintCouple::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppParCurves_HArray1OfConstraintCouple.def_static("operator delete_", (void (*)(void *, void *)) &AppParCurves_HArray1OfConstraintCouple::operator delete, "None", py::arg(""), py::arg(""));
// cls_AppParCurves_HArray1OfConstraintCouple.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &AppParCurves_HArray1OfConstraintCouple::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_AppParCurves_HArray1OfConstraintCouple.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &AppParCurves_HArray1OfConstraintCouple::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_AppParCurves_HArray1OfConstraintCouple.def("Array1", (const AppParCurves_Array1OfConstraintCouple & (AppParCurves_HArray1OfConstraintCouple::*)() const) &AppParCurves_HArray1OfConstraintCouple::Array1, "None");
cls_AppParCurves_HArray1OfConstraintCouple.def("ChangeArray1", (AppParCurves_Array1OfConstraintCouple & (AppParCurves_HArray1OfConstraintCouple::*)()) &AppParCurves_HArray1OfConstraintCouple::ChangeArray1, "None");
cls_AppParCurves_HArray1OfConstraintCouple.def_static("get_type_name_", (const char * (*)()) &AppParCurves_HArray1OfConstraintCouple::get_type_name, "None");
cls_AppParCurves_HArray1OfConstraintCouple.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AppParCurves_HArray1OfConstraintCouple::get_type_descriptor, "None");
cls_AppParCurves_HArray1OfConstraintCouple.def("DynamicType", (const opencascade::handle<Standard_Type> & (AppParCurves_HArray1OfConstraintCouple::*)() const) &AppParCurves_HArray1OfConstraintCouple::DynamicType, "None");

// TYPEDEF: APPPARCURVES_SEQUENCEOFMULTICURVE
bind_NCollection_Sequence<AppParCurves_MultiCurve>(mod, "AppParCurves_SequenceOfMultiCurve", py::module_local(false));

// CLASS: APPPARCURVES
py::class_<AppParCurves> cls_AppParCurves(mod, "AppParCurves", "Parallel Approximation in n curves. This package gives all the algorithms used to approximate a MultiLine described by the tool MLineTool. The result of the approximation will be a MultiCurve.");

// Methods
// cls_AppParCurves.def_static("operator new_", (void * (*)(size_t)) &AppParCurves::operator new, "None", py::arg("theSize"));
// cls_AppParCurves.def_static("operator delete_", (void (*)(void *)) &AppParCurves::operator delete, "None", py::arg("theAddress"));
// cls_AppParCurves.def_static("operator new[]_", (void * (*)(size_t)) &AppParCurves::operator new[], "None", py::arg("theSize"));
// cls_AppParCurves.def_static("operator delete[]_", (void (*)(void *)) &AppParCurves::operator delete[], "None", py::arg("theAddress"));
// cls_AppParCurves.def_static("operator new_", (void * (*)(size_t, void *)) &AppParCurves::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppParCurves.def_static("operator delete_", (void (*)(void *, void *)) &AppParCurves::operator delete, "None", py::arg(""), py::arg(""));
cls_AppParCurves.def_static("BernsteinMatrix_", (void (*)(const Standard_Integer, const math_Vector &, math_Matrix &)) &AppParCurves::BernsteinMatrix, "None", py::arg("NbPoles"), py::arg("U"), py::arg("A"));
cls_AppParCurves.def_static("Bernstein_", (void (*)(const Standard_Integer, const math_Vector &, math_Matrix &, math_Matrix &)) &AppParCurves::Bernstein, "None", py::arg("NbPoles"), py::arg("U"), py::arg("A"), py::arg("DA"));
cls_AppParCurves.def_static("SecondDerivativeBernstein_", (void (*)(const Standard_Real, math_Vector &)) &AppParCurves::SecondDerivativeBernstein, "None", py::arg("U"), py::arg("DDA"));
cls_AppParCurves.def_static("SplineFunction_", (void (*)(const Standard_Integer, const Standard_Integer, const math_Vector &, const math_Vector &, math_Matrix &, math_Matrix &, math_IntegerVector &)) &AppParCurves::SplineFunction, "None", py::arg("NbPoles"), py::arg("Degree"), py::arg("Parameters"), py::arg("FlatKnots"), py::arg("A"), py::arg("DA"), py::arg("Index"));

// TYPEDEF: APPPARCURVES_ARRAY1OFMULTIBSPCURVE
bind_NCollection_Array1<AppParCurves_MultiBSpCurve>(mod, "AppParCurves_Array1OfMultiBSpCurve", py::module_local(false));

// TYPEDEF: APPPARCURVES_ARRAY1OFMULTICURVE
bind_NCollection_Array1<AppParCurves_MultiCurve>(mod, "AppParCurves_Array1OfMultiCurve", py::module_local(false));

// CLASS: APPPARCURVES_HARRAY1OFMULTIBSPCURVE
py::class_<AppParCurves_HArray1OfMultiBSpCurve, opencascade::handle<AppParCurves_HArray1OfMultiBSpCurve>, Standard_Transient> cls_AppParCurves_HArray1OfMultiBSpCurve(mod, "AppParCurves_HArray1OfMultiBSpCurve", "None", py::multiple_inheritance());

// Constructors
cls_AppParCurves_HArray1OfMultiBSpCurve.def(py::init<>());
cls_AppParCurves_HArray1OfMultiBSpCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_AppParCurves_HArray1OfMultiBSpCurve.def(py::init<const Standard_Integer, const Standard_Integer, const AppParCurves_Array1OfMultiBSpCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_AppParCurves_HArray1OfMultiBSpCurve.def(py::init<const AppParCurves_Array1OfMultiBSpCurve &>(), py::arg("theOther"));

// Methods
// cls_AppParCurves_HArray1OfMultiBSpCurve.def_static("operator new_", (void * (*)(size_t)) &AppParCurves_HArray1OfMultiBSpCurve::operator new, "None", py::arg("theSize"));
// cls_AppParCurves_HArray1OfMultiBSpCurve.def_static("operator delete_", (void (*)(void *)) &AppParCurves_HArray1OfMultiBSpCurve::operator delete, "None", py::arg("theAddress"));
// cls_AppParCurves_HArray1OfMultiBSpCurve.def_static("operator new[]_", (void * (*)(size_t)) &AppParCurves_HArray1OfMultiBSpCurve::operator new[], "None", py::arg("theSize"));
// cls_AppParCurves_HArray1OfMultiBSpCurve.def_static("operator delete[]_", (void (*)(void *)) &AppParCurves_HArray1OfMultiBSpCurve::operator delete[], "None", py::arg("theAddress"));
// cls_AppParCurves_HArray1OfMultiBSpCurve.def_static("operator new_", (void * (*)(size_t, void *)) &AppParCurves_HArray1OfMultiBSpCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppParCurves_HArray1OfMultiBSpCurve.def_static("operator delete_", (void (*)(void *, void *)) &AppParCurves_HArray1OfMultiBSpCurve::operator delete, "None", py::arg(""), py::arg(""));
// cls_AppParCurves_HArray1OfMultiBSpCurve.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &AppParCurves_HArray1OfMultiBSpCurve::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_AppParCurves_HArray1OfMultiBSpCurve.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &AppParCurves_HArray1OfMultiBSpCurve::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_AppParCurves_HArray1OfMultiBSpCurve.def("Array1", (const AppParCurves_Array1OfMultiBSpCurve & (AppParCurves_HArray1OfMultiBSpCurve::*)() const) &AppParCurves_HArray1OfMultiBSpCurve::Array1, "None");
cls_AppParCurves_HArray1OfMultiBSpCurve.def("ChangeArray1", (AppParCurves_Array1OfMultiBSpCurve & (AppParCurves_HArray1OfMultiBSpCurve::*)()) &AppParCurves_HArray1OfMultiBSpCurve::ChangeArray1, "None");
cls_AppParCurves_HArray1OfMultiBSpCurve.def_static("get_type_name_", (const char * (*)()) &AppParCurves_HArray1OfMultiBSpCurve::get_type_name, "None");
cls_AppParCurves_HArray1OfMultiBSpCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AppParCurves_HArray1OfMultiBSpCurve::get_type_descriptor, "None");
cls_AppParCurves_HArray1OfMultiBSpCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (AppParCurves_HArray1OfMultiBSpCurve::*)() const) &AppParCurves_HArray1OfMultiBSpCurve::DynamicType, "None");

// CLASS: APPPARCURVES_HARRAY1OFMULTICURVE
py::class_<AppParCurves_HArray1OfMultiCurve, opencascade::handle<AppParCurves_HArray1OfMultiCurve>, Standard_Transient> cls_AppParCurves_HArray1OfMultiCurve(mod, "AppParCurves_HArray1OfMultiCurve", "None", py::multiple_inheritance());

// Constructors
cls_AppParCurves_HArray1OfMultiCurve.def(py::init<>());
cls_AppParCurves_HArray1OfMultiCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_AppParCurves_HArray1OfMultiCurve.def(py::init<const Standard_Integer, const Standard_Integer, const AppParCurves_Array1OfMultiCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_AppParCurves_HArray1OfMultiCurve.def(py::init<const AppParCurves_Array1OfMultiCurve &>(), py::arg("theOther"));

// Methods
// cls_AppParCurves_HArray1OfMultiCurve.def_static("operator new_", (void * (*)(size_t)) &AppParCurves_HArray1OfMultiCurve::operator new, "None", py::arg("theSize"));
// cls_AppParCurves_HArray1OfMultiCurve.def_static("operator delete_", (void (*)(void *)) &AppParCurves_HArray1OfMultiCurve::operator delete, "None", py::arg("theAddress"));
// cls_AppParCurves_HArray1OfMultiCurve.def_static("operator new[]_", (void * (*)(size_t)) &AppParCurves_HArray1OfMultiCurve::operator new[], "None", py::arg("theSize"));
// cls_AppParCurves_HArray1OfMultiCurve.def_static("operator delete[]_", (void (*)(void *)) &AppParCurves_HArray1OfMultiCurve::operator delete[], "None", py::arg("theAddress"));
// cls_AppParCurves_HArray1OfMultiCurve.def_static("operator new_", (void * (*)(size_t, void *)) &AppParCurves_HArray1OfMultiCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppParCurves_HArray1OfMultiCurve.def_static("operator delete_", (void (*)(void *, void *)) &AppParCurves_HArray1OfMultiCurve::operator delete, "None", py::arg(""), py::arg(""));
// cls_AppParCurves_HArray1OfMultiCurve.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &AppParCurves_HArray1OfMultiCurve::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_AppParCurves_HArray1OfMultiCurve.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &AppParCurves_HArray1OfMultiCurve::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_AppParCurves_HArray1OfMultiCurve.def("Array1", (const AppParCurves_Array1OfMultiCurve & (AppParCurves_HArray1OfMultiCurve::*)() const) &AppParCurves_HArray1OfMultiCurve::Array1, "None");
cls_AppParCurves_HArray1OfMultiCurve.def("ChangeArray1", (AppParCurves_Array1OfMultiCurve & (AppParCurves_HArray1OfMultiCurve::*)()) &AppParCurves_HArray1OfMultiCurve::ChangeArray1, "None");
cls_AppParCurves_HArray1OfMultiCurve.def_static("get_type_name_", (const char * (*)()) &AppParCurves_HArray1OfMultiCurve::get_type_name, "None");
cls_AppParCurves_HArray1OfMultiCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AppParCurves_HArray1OfMultiCurve::get_type_descriptor, "None");
cls_AppParCurves_HArray1OfMultiCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (AppParCurves_HArray1OfMultiCurve::*)() const) &AppParCurves_HArray1OfMultiCurve::DynamicType, "None");

// TYPEDEF: APPPARCURVES_SEQUENCEOFMULTIBSPCURVE
bind_NCollection_Sequence<AppParCurves_MultiBSpCurve>(mod, "AppParCurves_SequenceOfMultiBSpCurve", py::module_local(false));


}
