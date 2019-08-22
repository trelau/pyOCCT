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
#include <BRepLib_MakeShape.hxx>
#include <Standard.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Pln.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <gp_Sphere.hxx>
#include <gp_Torus.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Wire.hxx>
#include <BRepLib_FaceError.hxx>
#include <Geom_Curve.hxx>
#include <BRepLib_MakeFace.hxx>

void bind_BRepLib_MakeFace(py::module &mod){

py::class_<BRepLib_MakeFace, BRepLib_MakeShape> cls_BRepLib_MakeFace(mod, "BRepLib_MakeFace", "Provides methods to build faces.");

// Constructors
cls_BRepLib_MakeFace.def(py::init<>());
cls_BRepLib_MakeFace.def(py::init<const TopoDS_Face &>(), py::arg("F"));
cls_BRepLib_MakeFace.def(py::init<const gp_Pln &>(), py::arg("P"));
cls_BRepLib_MakeFace.def(py::init<const gp_Cylinder &>(), py::arg("C"));
cls_BRepLib_MakeFace.def(py::init<const gp_Cone &>(), py::arg("C"));
cls_BRepLib_MakeFace.def(py::init<const gp_Sphere &>(), py::arg("S"));
cls_BRepLib_MakeFace.def(py::init<const gp_Torus &>(), py::arg("C"));
cls_BRepLib_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("S"), py::arg("TolDegen"));
cls_BRepLib_MakeFace.def(py::init<const gp_Pln &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepLib_MakeFace.def(py::init<const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepLib_MakeFace.def(py::init<const gp_Cone &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepLib_MakeFace.def(py::init<const gp_Sphere &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepLib_MakeFace.def(py::init<const gp_Torus &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepLib_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("TolDegen"));
cls_BRepLib_MakeFace.def(py::init<const TopoDS_Wire &>(), py::arg("W"));
cls_BRepLib_MakeFace.def(py::init<const TopoDS_Wire &, const Standard_Boolean>(), py::arg("W"), py::arg("OnlyPlane"));
cls_BRepLib_MakeFace.def(py::init<const gp_Pln &, const TopoDS_Wire &>(), py::arg("P"), py::arg("W"));
cls_BRepLib_MakeFace.def(py::init<const gp_Pln &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("P"), py::arg("W"), py::arg("Inside"));
cls_BRepLib_MakeFace.def(py::init<const gp_Cylinder &, const TopoDS_Wire &>(), py::arg("C"), py::arg("W"));
cls_BRepLib_MakeFace.def(py::init<const gp_Cylinder &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("C"), py::arg("W"), py::arg("Inside"));
cls_BRepLib_MakeFace.def(py::init<const gp_Cone &, const TopoDS_Wire &>(), py::arg("C"), py::arg("W"));
cls_BRepLib_MakeFace.def(py::init<const gp_Cone &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("C"), py::arg("W"), py::arg("Inside"));
cls_BRepLib_MakeFace.def(py::init<const gp_Sphere &, const TopoDS_Wire &>(), py::arg("S"), py::arg("W"));
cls_BRepLib_MakeFace.def(py::init<const gp_Sphere &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("S"), py::arg("W"), py::arg("Inside"));
cls_BRepLib_MakeFace.def(py::init<const gp_Torus &, const TopoDS_Wire &>(), py::arg("C"), py::arg("W"));
cls_BRepLib_MakeFace.def(py::init<const gp_Torus &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("C"), py::arg("W"), py::arg("Inside"));
cls_BRepLib_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Wire &>(), py::arg("S"), py::arg("W"));
cls_BRepLib_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("S"), py::arg("W"), py::arg("Inside"));
cls_BRepLib_MakeFace.def(py::init<const TopoDS_Face &, const TopoDS_Wire &>(), py::arg("F"), py::arg("W"));

// Fields

// Methods
// cls_BRepLib_MakeFace.def_static("operator new_", (void * (*)(size_t)) &BRepLib_MakeFace::operator new, "None", py::arg("theSize"));
// cls_BRepLib_MakeFace.def_static("operator delete_", (void (*)(void *)) &BRepLib_MakeFace::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_MakeFace.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_MakeFace::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_MakeFace.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_MakeFace::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_MakeFace.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_MakeFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_MakeFace.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_MakeFace::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_MakeFace.def("Init", (void (BRepLib_MakeFace::*)(const TopoDS_Face &)) &BRepLib_MakeFace::Init, "Load the face.", py::arg("F"));
cls_BRepLib_MakeFace.def("Init", (void (BRepLib_MakeFace::*)(const opencascade::handle<Geom_Surface> &, const Standard_Boolean, const Standard_Real)) &BRepLib_MakeFace::Init, "Creates the face from the surface. If Bound is True a wire is made from the natural bounds. Accepts tolerance value (TolDegen) for resolution of degenerated edges.", py::arg("S"), py::arg("Bound"), py::arg("TolDegen"));
cls_BRepLib_MakeFace.def("Init", (void (BRepLib_MakeFace::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepLib_MakeFace::Init, "Creates the face from the surface and the min-max values. Accepts tolerance value (TolDegen) for resolution of degenerated edges.", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("TolDegen"));
cls_BRepLib_MakeFace.def("Add", (void (BRepLib_MakeFace::*)(const TopoDS_Wire &)) &BRepLib_MakeFace::Add, "Adds the wire <W> in the current face.", py::arg("W"));
cls_BRepLib_MakeFace.def("Error", (BRepLib_FaceError (BRepLib_MakeFace::*)() const) &BRepLib_MakeFace::Error, "None");
cls_BRepLib_MakeFace.def("Face", (const TopoDS_Face & (BRepLib_MakeFace::*)() const) &BRepLib_MakeFace::Face, "Returns the new face.");
cls_BRepLib_MakeFace.def_static("IsDegenerated_", [](const opencascade::handle<Geom_Curve> & theCurve, const Standard_Real theMaxTol, Standard_Real & theActTol){ Standard_Boolean rv = BRepLib_MakeFace::IsDegenerated(theCurve, theMaxTol, theActTol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theActTol); }, "Checks the specified curve is degenerated according to specified tolerance. Returns <theActTol> less than <theMaxTol>, which shows actual tolerance to decide the curve is degenerated. Warning: For internal use of BRepLib_MakeFace and BRepLib_MakeShell.", py::arg("theCurve"), py::arg("theMaxTol"), py::arg("theActTol"));

// Enums

}