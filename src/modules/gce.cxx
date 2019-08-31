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
#include <gce_ErrorType.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <gce_Root.hxx>
#include <gp_Ax2.hxx>
#include <gp_Circ.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_Pln.hxx>
#include <gp_Ax1.hxx>
#include <gce_MakeCirc.hxx>
#include <gp_Ax2d.hxx>
#include <gp_Ax22d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Pnt2d.hxx>
#include <gce_MakeCirc2d.hxx>
#include <gp_Cone.hxx>
#include <gp_Lin.hxx>
#include <gce_MakeCone.hxx>
#include <gp_Cylinder.hxx>
#include <gce_MakeCylinder.hxx>
#include <gp_Vec.hxx>
#include <gp_XYZ.hxx>
#include <gce_MakeDir.hxx>
#include <gp_Vec2d.hxx>
#include <gp_XY.hxx>
#include <gp_Dir2d.hxx>
#include <gce_MakeDir2d.hxx>
#include <gp_Elips.hxx>
#include <gce_MakeElips.hxx>
#include <gp_Elips2d.hxx>
#include <gce_MakeElips2d.hxx>
#include <gp_Hypr.hxx>
#include <gce_MakeHypr.hxx>
#include <gp_Hypr2d.hxx>
#include <gce_MakeHypr2d.hxx>
#include <gce_MakeLin.hxx>
#include <gp_Lin2d.hxx>
#include <gce_MakeLin2d.hxx>
#include <gp_Trsf.hxx>
#include <gce_MakeMirror.hxx>
#include <gp_Trsf2d.hxx>
#include <gce_MakeMirror2d.hxx>
#include <gp_Parab.hxx>
#include <gce_MakeParab.hxx>
#include <gp_Parab2d.hxx>
#include <gce_MakeParab2d.hxx>
#include <gce_MakePln.hxx>
#include <gce_MakeRotation.hxx>
#include <gce_MakeRotation2d.hxx>
#include <gce_MakeScale.hxx>
#include <gce_MakeScale2d.hxx>
#include <gce_MakeTranslation.hxx>
#include <gce_MakeTranslation2d.hxx>

PYBIND11_MODULE(gce, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");

// ENUM: GCE_ERRORTYPE
py::enum_<gce_ErrorType>(mod, "gce_ErrorType", "Indicates the outcome of a construction, i.e. whether it is successful or not, as explained below. gce_Done: Construction was successful. gce_ConfusedPoints: Two points are coincident. gce_NegativeRadius: Radius value is negative. gce_ColinearPoints: Three points are collinear. gce_IntersectionError: Intersection cannot be computed. gce_NullAxis: Axis is undefined. gce_NullAngle: Angle value is invalid (usually null). gce_NullRadius: Radius is null. gce_InvertAxis: Axis value is invalid. gce_BadAngle: Angle value is invalid. gce_InvertRadius: Radius value is incorrect (usually with respect to another radius). gce_NullFocusLength: Focal distance is null. gce_NullVector: Vector is null. gce_BadEquation: Coefficients are incorrect (applies to the equation of a geometric object).")
	.value("gce_Done", gce_ErrorType::gce_Done)
	.value("gce_ConfusedPoints", gce_ErrorType::gce_ConfusedPoints)
	.value("gce_NegativeRadius", gce_ErrorType::gce_NegativeRadius)
	.value("gce_ColinearPoints", gce_ErrorType::gce_ColinearPoints)
	.value("gce_IntersectionError", gce_ErrorType::gce_IntersectionError)
	.value("gce_NullAxis", gce_ErrorType::gce_NullAxis)
	.value("gce_NullAngle", gce_ErrorType::gce_NullAngle)
	.value("gce_NullRadius", gce_ErrorType::gce_NullRadius)
	.value("gce_InvertAxis", gce_ErrorType::gce_InvertAxis)
	.value("gce_BadAngle", gce_ErrorType::gce_BadAngle)
	.value("gce_InvertRadius", gce_ErrorType::gce_InvertRadius)
	.value("gce_NullFocusLength", gce_ErrorType::gce_NullFocusLength)
	.value("gce_NullVector", gce_ErrorType::gce_NullVector)
	.value("gce_BadEquation", gce_ErrorType::gce_BadEquation)
	.export_values();


// CLASS: GCE_ROOT
py::class_<gce_Root> cls_gce_Root(mod, "gce_Root", "This class implements the common services for all classes of gce which report error.");

// Methods
// cls_gce_Root.def_static("operator new_", (void * (*)(size_t)) &gce_Root::operator new, "None", py::arg("theSize"));
// cls_gce_Root.def_static("operator delete_", (void (*)(void *)) &gce_Root::operator delete, "None", py::arg("theAddress"));
// cls_gce_Root.def_static("operator new[]_", (void * (*)(size_t)) &gce_Root::operator new[], "None", py::arg("theSize"));
// cls_gce_Root.def_static("operator delete[]_", (void (*)(void *)) &gce_Root::operator delete[], "None", py::arg("theAddress"));
// cls_gce_Root.def_static("operator new_", (void * (*)(size_t, void *)) &gce_Root::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_Root.def_static("operator delete_", (void (*)(void *, void *)) &gce_Root::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_Root.def("IsDone", (Standard_Boolean (gce_Root::*)() const) &gce_Root::IsDone, "Returns true if the construction is successful.");
cls_gce_Root.def("Status", (gce_ErrorType (gce_Root::*)() const) &gce_Root::Status, "Returns the status of the construction: - gce_Done, if the construction is successful, or - another value of the gce_ErrorType enumeration indicating why the construction failed.");

// CLASS: GCE_MAKECIRC
py::class_<gce_MakeCirc, gce_Root> cls_gce_MakeCirc(mod, "gce_MakeCirc", "This class implements the following algorithms used to create Circ from gp.");

// Constructors
cls_gce_MakeCirc.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("A2"), py::arg("Radius"));
cls_gce_MakeCirc.def(py::init<const gp_Circ &, const Standard_Real>(), py::arg("Circ"), py::arg("Dist"));
cls_gce_MakeCirc.def(py::init<const gp_Circ &, const gp_Pnt &>(), py::arg("Circ"), py::arg("Point"));
cls_gce_MakeCirc.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_gce_MakeCirc.def(py::init<const gp_Pnt &, const gp_Dir &, const Standard_Real>(), py::arg("Center"), py::arg("Norm"), py::arg("Radius"));
cls_gce_MakeCirc.def(py::init<const gp_Pnt &, const gp_Pln &, const Standard_Real>(), py::arg("Center"), py::arg("Plane"), py::arg("Radius"));
cls_gce_MakeCirc.def(py::init<const gp_Pnt &, const gp_Pnt &, const Standard_Real>(), py::arg("Center"), py::arg("Ptaxis"), py::arg("Radius"));
cls_gce_MakeCirc.def(py::init<const gp_Ax1 &, const Standard_Real>(), py::arg("Axis"), py::arg("Radius"));

// Methods
// cls_gce_MakeCirc.def_static("operator new_", (void * (*)(size_t)) &gce_MakeCirc::operator new, "None", py::arg("theSize"));
// cls_gce_MakeCirc.def_static("operator delete_", (void (*)(void *)) &gce_MakeCirc::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeCirc.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeCirc::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeCirc.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeCirc::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeCirc.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeCirc::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeCirc.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeCirc::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeCirc.def("Value", (const gp_Circ & (gce_MakeCirc::*)() const) &gce_MakeCirc::Value, "Returns the constructed circle. Exceptions StdFail_NotDone if no circle is constructed.");
cls_gce_MakeCirc.def("Operator", (const gp_Circ & (gce_MakeCirc::*)() const) &gce_MakeCirc::Operator, "None");

// CLASS: GCE_MAKECIRC2D
py::class_<gce_MakeCirc2d, gce_Root> cls_gce_MakeCirc2d(mod, "gce_MakeCirc2d", "This class implements the following algorithms used to create Circ2d from gp.");

// Constructors
cls_gce_MakeCirc2d.def(py::init<const gp_Ax2d &, const Standard_Real>(), py::arg("XAxis"), py::arg("Radius"));
cls_gce_MakeCirc2d.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Boolean>(), py::arg("XAxis"), py::arg("Radius"), py::arg("Sense"));
cls_gce_MakeCirc2d.def(py::init<const gp_Ax22d &, const Standard_Real>(), py::arg("Axis"), py::arg("Radius"));
cls_gce_MakeCirc2d.def(py::init<const gp_Circ2d &, const Standard_Real>(), py::arg("Circ"), py::arg("Dist"));
cls_gce_MakeCirc2d.def(py::init<const gp_Circ2d &, const gp_Pnt2d &>(), py::arg("Circ"), py::arg("Point"));
cls_gce_MakeCirc2d.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_gce_MakeCirc2d.def(py::init<const gp_Pnt2d &, const Standard_Real>(), py::arg("Center"), py::arg("Radius"));
cls_gce_MakeCirc2d.def(py::init<const gp_Pnt2d &, const Standard_Real, const Standard_Boolean>(), py::arg("Center"), py::arg("Radius"), py::arg("Sense"));
cls_gce_MakeCirc2d.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("Center"), py::arg("Point"));
cls_gce_MakeCirc2d.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Boolean>(), py::arg("Center"), py::arg("Point"), py::arg("Sense"));

// Methods
// cls_gce_MakeCirc2d.def_static("operator new_", (void * (*)(size_t)) &gce_MakeCirc2d::operator new, "None", py::arg("theSize"));
// cls_gce_MakeCirc2d.def_static("operator delete_", (void (*)(void *)) &gce_MakeCirc2d::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeCirc2d.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeCirc2d::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeCirc2d.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeCirc2d::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeCirc2d.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeCirc2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeCirc2d.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeCirc2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeCirc2d.def("Value", (const gp_Circ2d & (gce_MakeCirc2d::*)() const) &gce_MakeCirc2d::Value, "Returns the constructed circle. Exceptions StdFail_NotDone if no circle is constructed.");
cls_gce_MakeCirc2d.def("Operator", (const gp_Circ2d & (gce_MakeCirc2d::*)() const) &gce_MakeCirc2d::Operator, "None");

// CLASS: GCE_MAKECONE
py::class_<gce_MakeCone, gce_Root> cls_gce_MakeCone(mod, "gce_MakeCone", "This class implements the following algorithms used to create a Cone from gp. * Create a Cone coaxial to another and passing through a point. * Create a Cone coaxial to another at a distance <Dist>. * Create a Cone by 4 points. * Create a Cone by its axis and 2 points. * Create a Cone by 2 points and 2 radius. * Create a Cone by an Ax2 an angle and the radius of its reference section.");

// Constructors
cls_gce_MakeCone.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("Ang"), py::arg("Radius"));
cls_gce_MakeCone.def(py::init<const gp_Cone &, const gp_Pnt &>(), py::arg("Cone"), py::arg("Point"));
cls_gce_MakeCone.def(py::init<const gp_Cone &, const Standard_Real>(), py::arg("Cone"), py::arg("Dist"));
cls_gce_MakeCone.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_gce_MakeCone.def(py::init<const gp_Ax1 &, const gp_Pnt &, const gp_Pnt &>(), py::arg("Axis"), py::arg("P1"), py::arg("P2"));
cls_gce_MakeCone.def(py::init<const gp_Lin &, const gp_Pnt &, const gp_Pnt &>(), py::arg("Axis"), py::arg("P1"), py::arg("P2"));
cls_gce_MakeCone.def(py::init<const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("P1"), py::arg("P2"), py::arg("R1"), py::arg("R2"));

// Methods
// cls_gce_MakeCone.def_static("operator new_", (void * (*)(size_t)) &gce_MakeCone::operator new, "None", py::arg("theSize"));
// cls_gce_MakeCone.def_static("operator delete_", (void (*)(void *)) &gce_MakeCone::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeCone.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeCone::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeCone.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeCone::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeCone.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeCone::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeCone.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeCone::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeCone.def("Value", (const gp_Cone & (gce_MakeCone::*)() const) &gce_MakeCone::Value, "Returns the constructed cone. Exceptions StdFail_NotDone if no cone is constructed.");
cls_gce_MakeCone.def("Operator", (const gp_Cone & (gce_MakeCone::*)() const) &gce_MakeCone::Operator, "None");

// CLASS: GCE_MAKECYLINDER
py::class_<gce_MakeCylinder, gce_Root> cls_gce_MakeCylinder(mod, "gce_MakeCylinder", "This class implements the following algorithms used to create a Cylinder from gp. * Create a Cylinder coaxial to another and passing through a point. * Create a Cylinder coaxial to another at a distance <Dist>. * Create a Cylinder with 3 points. * Create a Cylinder by its axis and radius. * Create a cylinder by its circular base.");

// Constructors
cls_gce_MakeCylinder.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("A2"), py::arg("Radius"));
cls_gce_MakeCylinder.def(py::init<const gp_Cylinder &, const gp_Pnt &>(), py::arg("Cyl"), py::arg("Point"));
cls_gce_MakeCylinder.def(py::init<const gp_Cylinder &, const Standard_Real>(), py::arg("Cyl"), py::arg("Dist"));
cls_gce_MakeCylinder.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_gce_MakeCylinder.def(py::init<const gp_Ax1 &, const Standard_Real>(), py::arg("Axis"), py::arg("Radius"));
cls_gce_MakeCylinder.def(py::init<const gp_Circ &>(), py::arg("Circ"));

// Methods
// cls_gce_MakeCylinder.def_static("operator new_", (void * (*)(size_t)) &gce_MakeCylinder::operator new, "None", py::arg("theSize"));
// cls_gce_MakeCylinder.def_static("operator delete_", (void (*)(void *)) &gce_MakeCylinder::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeCylinder.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeCylinder::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeCylinder.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeCylinder::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeCylinder.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeCylinder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeCylinder.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeCylinder::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeCylinder.def("Value", (const gp_Cylinder & (gce_MakeCylinder::*)() const) &gce_MakeCylinder::Value, "Returns the constructed cylinder. Exceptions StdFail_NotDone if no cylinder is constructed.");
cls_gce_MakeCylinder.def("Operator", (const gp_Cylinder & (gce_MakeCylinder::*)() const) &gce_MakeCylinder::Operator, "None");

// CLASS: GCE_MAKEDIR
py::class_<gce_MakeDir, gce_Root> cls_gce_MakeDir(mod, "gce_MakeDir", "This class implements the following algorithms used to create a Dir from gp. * Create a Dir parallel to another and passing through a point. * Create a Dir passing through 2 points. * Create a Dir from its axis (Ax1 from gp). * Create a Dir from a point and a direction.");

// Constructors
cls_gce_MakeDir.def(py::init<const gp_Vec &>(), py::arg("V"));
cls_gce_MakeDir.def(py::init<const gp_XYZ &>(), py::arg("Coord"));
cls_gce_MakeDir.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Xv"), py::arg("Yv"), py::arg("Zv"));
cls_gce_MakeDir.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));

// Methods
// cls_gce_MakeDir.def_static("operator new_", (void * (*)(size_t)) &gce_MakeDir::operator new, "None", py::arg("theSize"));
// cls_gce_MakeDir.def_static("operator delete_", (void (*)(void *)) &gce_MakeDir::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeDir.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeDir::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeDir.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeDir::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeDir.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeDir::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeDir.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeDir::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeDir.def("Value", (const gp_Dir & (gce_MakeDir::*)() const) &gce_MakeDir::Value, "Returns the constructed unit vector. Exceptions StdFail_NotDone if no unit vector is constructed.");
cls_gce_MakeDir.def("Operator", (const gp_Dir & (gce_MakeDir::*)() const) &gce_MakeDir::Operator, "None");

// CLASS: GCE_MAKEDIR2D
py::class_<gce_MakeDir2d, gce_Root> cls_gce_MakeDir2d(mod, "gce_MakeDir2d", "This class implements the following algorithms used to create a Dir2d from gp. * Create a Dir2d with 2 points. * Create a Dir2d with a Vec2d. * Create a Dir2d with a XY from gp. * Create a Dir2d with a 2 Reals (Coordinates).");

// Constructors
cls_gce_MakeDir2d.def(py::init<const gp_Vec2d &>(), py::arg("V"));
cls_gce_MakeDir2d.def(py::init<const gp_XY &>(), py::arg("Coord"));
cls_gce_MakeDir2d.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("Xv"), py::arg("Yv"));
cls_gce_MakeDir2d.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("P2"));

// Methods
// cls_gce_MakeDir2d.def_static("operator new_", (void * (*)(size_t)) &gce_MakeDir2d::operator new, "None", py::arg("theSize"));
// cls_gce_MakeDir2d.def_static("operator delete_", (void (*)(void *)) &gce_MakeDir2d::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeDir2d.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeDir2d::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeDir2d.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeDir2d::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeDir2d.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeDir2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeDir2d.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeDir2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeDir2d.def("Value", (const gp_Dir2d & (gce_MakeDir2d::*)() const) &gce_MakeDir2d::Value, "Returns the constructed unit vector. Exceptions StdFail_NotDone if no unit vector is constructed.");
cls_gce_MakeDir2d.def("Operator", (const gp_Dir2d & (gce_MakeDir2d::*)() const) &gce_MakeDir2d::Operator, "None");

// CLASS: GCE_MAKEELIPS
py::class_<gce_MakeElips, gce_Root> cls_gce_MakeElips(mod, "gce_MakeElips", "This class implements the following algorithms used to create an ellipse from gp.");

// Constructors
cls_gce_MakeElips.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("MajorRadius"), py::arg("MinorRadius"));
cls_gce_MakeElips.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("S1"), py::arg("S2"), py::arg("Center"));

// Methods
// cls_gce_MakeElips.def_static("operator new_", (void * (*)(size_t)) &gce_MakeElips::operator new, "None", py::arg("theSize"));
// cls_gce_MakeElips.def_static("operator delete_", (void (*)(void *)) &gce_MakeElips::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeElips.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeElips::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeElips.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeElips::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeElips.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeElips::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeElips.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeElips::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeElips.def("Value", (const gp_Elips & (gce_MakeElips::*)() const) &gce_MakeElips::Value, "Returns the constructed ellipse. Exceptions StdFail_NotDone if no ellipse is constructed.");
cls_gce_MakeElips.def("Operator", (const gp_Elips & (gce_MakeElips::*)() const) &gce_MakeElips::Operator, "None");

// CLASS: GCE_MAKEELIPS2D
py::class_<gce_MakeElips2d, gce_Root> cls_gce_MakeElips2d(mod, "gce_MakeElips2d", "This class implements the following algorithms used to create Elips2d from gp.");

// Constructors
cls_gce_MakeElips2d.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"));
cls_gce_MakeElips2d.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"), py::arg("Sense"));
cls_gce_MakeElips2d.def(py::init<const gp_Ax22d &, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("MajorRadius"), py::arg("MinorRadius"));
cls_gce_MakeElips2d.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("S1"), py::arg("S2"), py::arg("Center"));

// Methods
// cls_gce_MakeElips2d.def_static("operator new_", (void * (*)(size_t)) &gce_MakeElips2d::operator new, "None", py::arg("theSize"));
// cls_gce_MakeElips2d.def_static("operator delete_", (void (*)(void *)) &gce_MakeElips2d::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeElips2d.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeElips2d::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeElips2d.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeElips2d::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeElips2d.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeElips2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeElips2d.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeElips2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeElips2d.def("Value", (const gp_Elips2d & (gce_MakeElips2d::*)() const) &gce_MakeElips2d::Value, "Returns the constructed ellipse. Exceptions StdFail_NotDone if no ellipse is constructed.");
cls_gce_MakeElips2d.def("Operator", (const gp_Elips2d & (gce_MakeElips2d::*)() const) &gce_MakeElips2d::Operator, "None");

// CLASS: GCE_MAKEHYPR
py::class_<gce_MakeHypr, gce_Root> cls_gce_MakeHypr(mod, "gce_MakeHypr", "This class implements the following algorithms used to create Hyperbola from gp. * Create an Hyperbola from its center, and two points: one on its axis of symmetry giving the major radius, the other giving the value of the small radius. The three points give the plane of the hyperbola. * Create an hyperbola from its axisplacement and its MajorRadius and its MinorRadius.");

// Constructors
cls_gce_MakeHypr.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("MajorRadius"), py::arg("MinorRadius"));
cls_gce_MakeHypr.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("S1"), py::arg("S2"), py::arg("Center"));

// Methods
// cls_gce_MakeHypr.def_static("operator new_", (void * (*)(size_t)) &gce_MakeHypr::operator new, "None", py::arg("theSize"));
// cls_gce_MakeHypr.def_static("operator delete_", (void (*)(void *)) &gce_MakeHypr::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeHypr.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeHypr::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeHypr.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeHypr::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeHypr.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeHypr::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeHypr.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeHypr::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeHypr.def("Value", (const gp_Hypr & (gce_MakeHypr::*)() const) &gce_MakeHypr::Value, "Returns the constructed hyperbola. Exceptions StdFail_NotDone if no hyperbola is constructed.");
cls_gce_MakeHypr.def("Operator", (const gp_Hypr & (gce_MakeHypr::*)() const) &gce_MakeHypr::Operator, "None");

// CLASS: GCE_MAKEHYPR2D
py::class_<gce_MakeHypr2d, gce_Root> cls_gce_MakeHypr2d(mod, "gce_MakeHypr2d", "This class implements the following algorithms used to create a 2d Hyperbola from gp. * Create a 2d Hyperbola from its center and two points: one on its axis of symmetry giving the major radius, the other giving the value of the small radius. * Create a 2d Hyperbola from its major axis and its major radius and its minor radius.");

// Constructors
cls_gce_MakeHypr2d.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("S1"), py::arg("S2"), py::arg("Center"));
cls_gce_MakeHypr2d.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"), py::arg("Sense"));
cls_gce_MakeHypr2d.def(py::init<const gp_Ax22d &, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("MajorRadius"), py::arg("MinorRadius"));

// Methods
// cls_gce_MakeHypr2d.def_static("operator new_", (void * (*)(size_t)) &gce_MakeHypr2d::operator new, "None", py::arg("theSize"));
// cls_gce_MakeHypr2d.def_static("operator delete_", (void (*)(void *)) &gce_MakeHypr2d::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeHypr2d.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeHypr2d::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeHypr2d.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeHypr2d::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeHypr2d.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeHypr2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeHypr2d.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeHypr2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeHypr2d.def("Value", (const gp_Hypr2d & (gce_MakeHypr2d::*)() const) &gce_MakeHypr2d::Value, "Returns the constructed hyperbola. Exceptions StdFail_NotDone if no hyperbola is constructed.");
cls_gce_MakeHypr2d.def("Operator", (const gp_Hypr2d & (gce_MakeHypr2d::*)() const) &gce_MakeHypr2d::Operator, "None");

// CLASS: GCE_MAKELIN
py::class_<gce_MakeLin, gce_Root> cls_gce_MakeLin(mod, "gce_MakeLin", "This class implements the following algorithms used to create a Lin from gp. * Create a Lin parallel to another and passing through a point. * Create a Lin passing through 2 points. * Create a lin from its axis (Ax1 from gp). * Create a lin from a point and a direction.");

// Constructors
cls_gce_MakeLin.def(py::init<const gp_Ax1 &>(), py::arg("A1"));
cls_gce_MakeLin.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));
cls_gce_MakeLin.def(py::init<const gp_Lin &, const gp_Pnt &>(), py::arg("Lin"), py::arg("Point"));
cls_gce_MakeLin.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));

// Methods
// cls_gce_MakeLin.def_static("operator new_", (void * (*)(size_t)) &gce_MakeLin::operator new, "None", py::arg("theSize"));
// cls_gce_MakeLin.def_static("operator delete_", (void (*)(void *)) &gce_MakeLin::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeLin.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeLin::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeLin.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeLin::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeLin.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeLin::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeLin.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeLin::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeLin.def("Value", (const gp_Lin & (gce_MakeLin::*)() const) &gce_MakeLin::Value, "Returns the constructed line. Exceptions StdFail_NotDone is raised if no line is constructed.");
cls_gce_MakeLin.def("Operator", (const gp_Lin & (gce_MakeLin::*)() const) &gce_MakeLin::Operator, "None");

// CLASS: GCE_MAKELIN2D
py::class_<gce_MakeLin2d, gce_Root> cls_gce_MakeLin2d(mod, "gce_MakeLin2d", "This class implements the following algorithms used to create Lin2d from gp.");

// Constructors
cls_gce_MakeLin2d.def(py::init<const gp_Ax2d &>(), py::arg("A"));
cls_gce_MakeLin2d.def(py::init<const gp_Pnt2d &, const gp_Dir2d &>(), py::arg("P"), py::arg("V"));
cls_gce_MakeLin2d.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"));
cls_gce_MakeLin2d.def(py::init<const gp_Lin2d &, const Standard_Real>(), py::arg("Lin"), py::arg("Dist"));
cls_gce_MakeLin2d.def(py::init<const gp_Lin2d &, const gp_Pnt2d &>(), py::arg("Lin"), py::arg("Point"));
cls_gce_MakeLin2d.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("P2"));

// Methods
// cls_gce_MakeLin2d.def_static("operator new_", (void * (*)(size_t)) &gce_MakeLin2d::operator new, "None", py::arg("theSize"));
// cls_gce_MakeLin2d.def_static("operator delete_", (void (*)(void *)) &gce_MakeLin2d::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeLin2d.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeLin2d::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeLin2d.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeLin2d::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeLin2d.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeLin2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeLin2d.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeLin2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeLin2d.def("Value", (gp_Lin2d (gce_MakeLin2d::*)() const) &gce_MakeLin2d::Value, "Returns the constructed line. Exceptions StdFail_NotDone if no line is constructed.");
cls_gce_MakeLin2d.def("Operator", (gp_Lin2d (gce_MakeLin2d::*)() const) &gce_MakeLin2d::Operator, "None");

// CLASS: GCE_MAKEMIRROR
py::class_<gce_MakeMirror> cls_gce_MakeMirror(mod, "gce_MakeMirror", "This class mplements elementary construction algorithms for a symmetrical transformation in 3D space about a point, axis or plane. The result is a gp_Trsf transformation. A MakeMirror object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_gce_MakeMirror.def(py::init<const gp_Pnt &>(), py::arg("Point"));
cls_gce_MakeMirror.def(py::init<const gp_Ax1 &>(), py::arg("Axis"));
cls_gce_MakeMirror.def(py::init<const gp_Lin &>(), py::arg("Line"));
cls_gce_MakeMirror.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("Point"), py::arg("Direc"));
cls_gce_MakeMirror.def(py::init<const gp_Pln &>(), py::arg("Plane"));
cls_gce_MakeMirror.def(py::init<const gp_Ax2 &>(), py::arg("Plane"));

// Methods
// cls_gce_MakeMirror.def_static("operator new_", (void * (*)(size_t)) &gce_MakeMirror::operator new, "None", py::arg("theSize"));
// cls_gce_MakeMirror.def_static("operator delete_", (void (*)(void *)) &gce_MakeMirror::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeMirror.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeMirror::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeMirror.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeMirror::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeMirror.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeMirror::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeMirror.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeMirror::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeMirror.def("Value", (const gp_Trsf & (gce_MakeMirror::*)() const) &gce_MakeMirror::Value, "Returns the constructed transformation.");
cls_gce_MakeMirror.def("Operator", (const gp_Trsf & (gce_MakeMirror::*)() const) &gce_MakeMirror::Operator, "None");

// CLASS: GCE_MAKEMIRROR2D
py::class_<gce_MakeMirror2d> cls_gce_MakeMirror2d(mod, "gce_MakeMirror2d", "This class implements elementary construction algorithms for a symmetrical transformation in 2D space about a point or axis. The result is a gp_Trsf2d transformation. A MakeMirror2d object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and consulting the result.");

// Constructors
cls_gce_MakeMirror2d.def(py::init<const gp_Pnt2d &>(), py::arg("Point"));
cls_gce_MakeMirror2d.def(py::init<const gp_Ax2d &>(), py::arg("Axis"));
cls_gce_MakeMirror2d.def(py::init<const gp_Lin2d &>(), py::arg("Line"));
cls_gce_MakeMirror2d.def(py::init<const gp_Pnt2d &, const gp_Dir2d &>(), py::arg("Point"), py::arg("Direc"));

// Methods
// cls_gce_MakeMirror2d.def_static("operator new_", (void * (*)(size_t)) &gce_MakeMirror2d::operator new, "None", py::arg("theSize"));
// cls_gce_MakeMirror2d.def_static("operator delete_", (void (*)(void *)) &gce_MakeMirror2d::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeMirror2d.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeMirror2d::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeMirror2d.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeMirror2d::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeMirror2d.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeMirror2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeMirror2d.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeMirror2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeMirror2d.def("Value", (const gp_Trsf2d & (gce_MakeMirror2d::*)() const) &gce_MakeMirror2d::Value, "Returns the constructed transformation.");
cls_gce_MakeMirror2d.def("Operator", (const gp_Trsf2d & (gce_MakeMirror2d::*)() const) &gce_MakeMirror2d::Operator, "None");

// CLASS: GCE_MAKEPARAB
py::class_<gce_MakeParab, gce_Root> cls_gce_MakeParab(mod, "gce_MakeParab", "This class implements the following algorithms used to create Parab from gp. Defines the parabola in the parameterization range : ]-infinite, +infinite[ The vertex of the parabola is the 'Location' point of the local coordinate system (axis placement) of the parabola.");

// Constructors
cls_gce_MakeParab.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("A2"), py::arg("Focal"));
cls_gce_MakeParab.def(py::init<const gp_Ax1 &, const gp_Pnt &>(), py::arg("D"), py::arg("F"));

// Methods
// cls_gce_MakeParab.def_static("operator new_", (void * (*)(size_t)) &gce_MakeParab::operator new, "None", py::arg("theSize"));
// cls_gce_MakeParab.def_static("operator delete_", (void (*)(void *)) &gce_MakeParab::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeParab.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeParab::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeParab.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeParab::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeParab.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeParab::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeParab.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeParab::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeParab.def("Value", (const gp_Parab & (gce_MakeParab::*)() const) &gce_MakeParab::Value, "Returns the constructed parabola. Exceptions StdFail_NotDone if no parabola is constructed.");
cls_gce_MakeParab.def("Operator", (const gp_Parab & (gce_MakeParab::*)() const) &gce_MakeParab::Operator, "None");

// CLASS: GCE_MAKEPARAB2D
py::class_<gce_MakeParab2d, gce_Root> cls_gce_MakeParab2d(mod, "gce_MakeParab2d", "This class implements the following algorithms used to create Parab2d from gp. Defines an infinite parabola. An axis placement one axis defines the local cartesian coordinate system ('XAxis') of the parabola. The vertex of the parabola is the 'Location' point of the local coordinate system of the parabola. The 'XAxis' of the parabola is its axis of symmetry. The 'XAxis' is oriented from the vertex of the parabola to the Focus of the parabola. The 'YAxis' is parallel to the directrix of the parabola and its 'Location' point is the vertex of the parabola. The equation of the parabola in the local coordinate system is Y**2 = (2*P) * X P is the distance between the focus and the directrix of the parabola called Parameter). The focal length F = P/2 is the distance between the vertex and the focus of the parabola.");

// Constructors
cls_gce_MakeParab2d.def(py::init<const gp_Ax2d &, const Standard_Real>(), py::arg("MirrorAxis"), py::arg("Focal"));
cls_gce_MakeParab2d.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Boolean>(), py::arg("MirrorAxis"), py::arg("Focal"), py::arg("Sense"));
cls_gce_MakeParab2d.def(py::init<const gp_Ax22d &, const Standard_Real>(), py::arg("A"), py::arg("Focal"));
cls_gce_MakeParab2d.def(py::init<const gp_Ax2d &, const gp_Pnt2d &>(), py::arg("D"), py::arg("F"));
cls_gce_MakeParab2d.def(py::init<const gp_Ax2d &, const gp_Pnt2d &, const Standard_Boolean>(), py::arg("D"), py::arg("F"), py::arg("Sense"));
cls_gce_MakeParab2d.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("S1"), py::arg("Center"));
cls_gce_MakeParab2d.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Boolean>(), py::arg("S1"), py::arg("Center"), py::arg("Sense"));

// Methods
// cls_gce_MakeParab2d.def_static("operator new_", (void * (*)(size_t)) &gce_MakeParab2d::operator new, "None", py::arg("theSize"));
// cls_gce_MakeParab2d.def_static("operator delete_", (void (*)(void *)) &gce_MakeParab2d::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeParab2d.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeParab2d::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeParab2d.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeParab2d::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeParab2d.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeParab2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeParab2d.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeParab2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeParab2d.def("Value", (const gp_Parab2d & (gce_MakeParab2d::*)() const) &gce_MakeParab2d::Value, "Returns the constructed parabola. Exceptions StdFail_NotDone if no parabola is constructed.");
cls_gce_MakeParab2d.def("Operator", (const gp_Parab2d & (gce_MakeParab2d::*)() const) &gce_MakeParab2d::Operator, "None");

// CLASS: GCE_MAKEPLN
py::class_<gce_MakePln, gce_Root> cls_gce_MakePln(mod, "gce_MakePln", "This class implements the following algorithms used to create a Plane from gp. * Create a Pln parallel to another and passing through a point. * Create a Pln passing through 3 points. * Create a Pln by its normal. Defines a non-persistent plane. The plane is located in 3D space with an axis placement two axis. It is the local coordinate system of the plane.");

// Constructors
cls_gce_MakePln.def(py::init<const gp_Ax2 &>(), py::arg("A2"));
cls_gce_MakePln.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));
cls_gce_MakePln.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
cls_gce_MakePln.def(py::init<const gp_Pln &, const gp_Pnt &>(), py::arg("Pln"), py::arg("Point"));
cls_gce_MakePln.def(py::init<const gp_Pln &, const Standard_Real>(), py::arg("Pln"), py::arg("Dist"));
cls_gce_MakePln.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_gce_MakePln.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));
cls_gce_MakePln.def(py::init<const gp_Ax1 &>(), py::arg("Axis"));

// Methods
// cls_gce_MakePln.def_static("operator new_", (void * (*)(size_t)) &gce_MakePln::operator new, "None", py::arg("theSize"));
// cls_gce_MakePln.def_static("operator delete_", (void (*)(void *)) &gce_MakePln::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakePln.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakePln::operator new[], "None", py::arg("theSize"));
// cls_gce_MakePln.def_static("operator delete[]_", (void (*)(void *)) &gce_MakePln::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakePln.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakePln::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakePln.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakePln::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakePln.def("Value", (const gp_Pln & (gce_MakePln::*)() const) &gce_MakePln::Value, "Returns the constructed plane. Exceptions StdFail_NotDone if no plane is constructed.");
cls_gce_MakePln.def("Operator", (const gp_Pln & (gce_MakePln::*)() const) &gce_MakePln::Operator, "None");

// CLASS: GCE_MAKEROTATION
py::class_<gce_MakeRotation> cls_gce_MakeRotation(mod, "gce_MakeRotation", "This class implements elementary construction algorithms for a rotation in 3D space. The result is a gp_Trsf transformation. A MakeRotation object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_gce_MakeRotation.def(py::init<const gp_Lin &, const Standard_Real>(), py::arg("Line"), py::arg("Angle"));
cls_gce_MakeRotation.def(py::init<const gp_Ax1 &, const Standard_Real>(), py::arg("Axis"), py::arg("Angle"));
cls_gce_MakeRotation.def(py::init<const gp_Pnt &, const gp_Dir &, const Standard_Real>(), py::arg("Point"), py::arg("Direc"), py::arg("Angle"));

// Methods
// cls_gce_MakeRotation.def_static("operator new_", (void * (*)(size_t)) &gce_MakeRotation::operator new, "None", py::arg("theSize"));
// cls_gce_MakeRotation.def_static("operator delete_", (void (*)(void *)) &gce_MakeRotation::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeRotation.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeRotation::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeRotation.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeRotation::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeRotation.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeRotation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeRotation.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeRotation::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeRotation.def("Value", (const gp_Trsf & (gce_MakeRotation::*)() const) &gce_MakeRotation::Value, "Returns the constructed transformation.");
cls_gce_MakeRotation.def("Operator", (const gp_Trsf & (gce_MakeRotation::*)() const) &gce_MakeRotation::Operator, "None");

// CLASS: GCE_MAKEROTATION2D
py::class_<gce_MakeRotation2d> cls_gce_MakeRotation2d(mod, "gce_MakeRotation2d", "Implements an elementary construction algorithm for a rotation in 2D space. The result is a gp_Trsf2d transformation. A MakeRotation2d object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_gce_MakeRotation2d.def(py::init<const gp_Pnt2d &, const Standard_Real>(), py::arg("Point"), py::arg("Angle"));

// Methods
// cls_gce_MakeRotation2d.def_static("operator new_", (void * (*)(size_t)) &gce_MakeRotation2d::operator new, "None", py::arg("theSize"));
// cls_gce_MakeRotation2d.def_static("operator delete_", (void (*)(void *)) &gce_MakeRotation2d::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeRotation2d.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeRotation2d::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeRotation2d.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeRotation2d::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeRotation2d.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeRotation2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeRotation2d.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeRotation2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeRotation2d.def("Value", (const gp_Trsf2d & (gce_MakeRotation2d::*)() const) &gce_MakeRotation2d::Value, "Returns the constructed transformation.");
cls_gce_MakeRotation2d.def("Operator", (const gp_Trsf2d & (gce_MakeRotation2d::*)() const) &gce_MakeRotation2d::Operator, "None");

// CLASS: GCE_MAKESCALE
py::class_<gce_MakeScale> cls_gce_MakeScale(mod, "gce_MakeScale", "Implements an elementary construction algorithm for a scaling transformation in 3D space. The result is a gp_Trsf transformation. A MakeScale object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_gce_MakeScale.def(py::init<const gp_Pnt &, const Standard_Real>(), py::arg("Point"), py::arg("Scale"));

// Methods
// cls_gce_MakeScale.def_static("operator new_", (void * (*)(size_t)) &gce_MakeScale::operator new, "None", py::arg("theSize"));
// cls_gce_MakeScale.def_static("operator delete_", (void (*)(void *)) &gce_MakeScale::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeScale.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeScale::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeScale.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeScale::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeScale.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeScale::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeScale.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeScale::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeScale.def("Value", (const gp_Trsf & (gce_MakeScale::*)() const) &gce_MakeScale::Value, "Returns the constructed transformation.");
cls_gce_MakeScale.def("Operator", (const gp_Trsf & (gce_MakeScale::*)() const) &gce_MakeScale::Operator, "None");

// CLASS: GCE_MAKESCALE2D
py::class_<gce_MakeScale2d> cls_gce_MakeScale2d(mod, "gce_MakeScale2d", "This class implements an elementary construction algorithm for a scaling transformation in 2D space. The result is a gp_Trsf2d transformation. A MakeScale2d object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_gce_MakeScale2d.def(py::init<const gp_Pnt2d &, const Standard_Real>(), py::arg("Point"), py::arg("Scale"));

// Methods
// cls_gce_MakeScale2d.def_static("operator new_", (void * (*)(size_t)) &gce_MakeScale2d::operator new, "None", py::arg("theSize"));
// cls_gce_MakeScale2d.def_static("operator delete_", (void (*)(void *)) &gce_MakeScale2d::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeScale2d.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeScale2d::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeScale2d.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeScale2d::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeScale2d.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeScale2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeScale2d.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeScale2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeScale2d.def("Value", (const gp_Trsf2d & (gce_MakeScale2d::*)() const) &gce_MakeScale2d::Value, "Returns the constructed transformation.");
cls_gce_MakeScale2d.def("Operator", (const gp_Trsf2d & (gce_MakeScale2d::*)() const) &gce_MakeScale2d::Operator, "None");

// CLASS: GCE_MAKETRANSLATION
py::class_<gce_MakeTranslation> cls_gce_MakeTranslation(mod, "gce_MakeTranslation", "This class implements elementary construction algorithms for a translation in 3D space. The result is a gp_Trsf transformation. A MakeTranslation object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_gce_MakeTranslation.def(py::init<const gp_Vec &>(), py::arg("Vect"));
cls_gce_MakeTranslation.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("Point1"), py::arg("Point2"));

// Methods
// cls_gce_MakeTranslation.def_static("operator new_", (void * (*)(size_t)) &gce_MakeTranslation::operator new, "None", py::arg("theSize"));
// cls_gce_MakeTranslation.def_static("operator delete_", (void (*)(void *)) &gce_MakeTranslation::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeTranslation.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeTranslation::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeTranslation.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeTranslation::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeTranslation.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeTranslation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeTranslation.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeTranslation::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeTranslation.def("Value", (const gp_Trsf & (gce_MakeTranslation::*)() const) &gce_MakeTranslation::Value, "Returns the constructed transformation.");
cls_gce_MakeTranslation.def("Operator", (const gp_Trsf & (gce_MakeTranslation::*)() const) &gce_MakeTranslation::Operator, "None");

// CLASS: GCE_MAKETRANSLATION2D
py::class_<gce_MakeTranslation2d> cls_gce_MakeTranslation2d(mod, "gce_MakeTranslation2d", "This class implements elementary construction algorithms for a translation in 2D space. The result is a gp_Trsf2d transformation. A MakeTranslation2d object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_gce_MakeTranslation2d.def(py::init<const gp_Vec2d &>(), py::arg("Vect"));
cls_gce_MakeTranslation2d.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("Point1"), py::arg("Point2"));

// Methods
// cls_gce_MakeTranslation2d.def_static("operator new_", (void * (*)(size_t)) &gce_MakeTranslation2d::operator new, "None", py::arg("theSize"));
// cls_gce_MakeTranslation2d.def_static("operator delete_", (void (*)(void *)) &gce_MakeTranslation2d::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeTranslation2d.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeTranslation2d::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeTranslation2d.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeTranslation2d::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeTranslation2d.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeTranslation2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeTranslation2d.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeTranslation2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeTranslation2d.def("Value", (const gp_Trsf2d & (gce_MakeTranslation2d::*)() const) &gce_MakeTranslation2d::Value, "Returns the constructed transformation.");
cls_gce_MakeTranslation2d.def("Operator", (const gp_Trsf2d & (gce_MakeTranslation2d::*)() const) &gce_MakeTranslation2d::Operator, "None");


}
