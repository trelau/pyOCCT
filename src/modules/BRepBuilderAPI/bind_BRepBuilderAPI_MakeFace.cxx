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
#include <BRepBuilderAPI_MakeShape.hxx>
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
#include <BRepBuilderAPI_FaceError.hxx>
#include <BRepLib_MakeFace.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>

void bind_BRepBuilderAPI_MakeFace(py::module &mod){

py::class_<BRepBuilderAPI_MakeFace, std::unique_ptr<BRepBuilderAPI_MakeFace, Deleter<BRepBuilderAPI_MakeFace>>, BRepBuilderAPI_MakeShape> cls_BRepBuilderAPI_MakeFace(mod, "BRepBuilderAPI_MakeFace", "Provides methods to build faces.");

// Constructors
cls_BRepBuilderAPI_MakeFace.def(py::init<>());
cls_BRepBuilderAPI_MakeFace.def(py::init<const TopoDS_Face &>(), py::arg("F"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Pln &>(), py::arg("P"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Cylinder &>(), py::arg("C"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Cone &>(), py::arg("C"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Sphere &>(), py::arg("S"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Torus &>(), py::arg("C"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("S"), py::arg("TolDegen"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Pln &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Cone &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Sphere &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Torus &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("TolDegen"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const TopoDS_Wire &>(), py::arg("W"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const TopoDS_Wire &, const Standard_Boolean>(), py::arg("W"), py::arg("OnlyPlane"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Pln &, const TopoDS_Wire &>(), py::arg("P"), py::arg("W"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Pln &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("P"), py::arg("W"), py::arg("Inside"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Cylinder &, const TopoDS_Wire &>(), py::arg("C"), py::arg("W"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Cylinder &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("C"), py::arg("W"), py::arg("Inside"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Cone &, const TopoDS_Wire &>(), py::arg("C"), py::arg("W"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Cone &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("C"), py::arg("W"), py::arg("Inside"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Sphere &, const TopoDS_Wire &>(), py::arg("S"), py::arg("W"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Sphere &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("S"), py::arg("W"), py::arg("Inside"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Torus &, const TopoDS_Wire &>(), py::arg("C"), py::arg("W"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Torus &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("C"), py::arg("W"), py::arg("Inside"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Wire &>(), py::arg("S"), py::arg("W"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("S"), py::arg("W"), py::arg("Inside"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const TopoDS_Face &, const TopoDS_Wire &>(), py::arg("F"), py::arg("W"));

// Fields

// Methods
// cls_BRepBuilderAPI_MakeFace.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_MakeFace::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeFace.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_MakeFace::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeFace.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_MakeFace::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeFace.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_MakeFace::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeFace.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_MakeFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeFace.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_MakeFace::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_MakeFace.def("Init", (void (BRepBuilderAPI_MakeFace::*)(const TopoDS_Face &)) &BRepBuilderAPI_MakeFace::Init, "Initializes (or reinitializes) the construction of a face by creating a new object which is a copy of the face F, in order to add wires to it, using the function Add. Note: this complete copy of the geometry is only required if you want to work on the geometries of the two faces independently.", py::arg("F"));
cls_BRepBuilderAPI_MakeFace.def("Init", (void (BRepBuilderAPI_MakeFace::*)(const opencascade::handle<Geom_Surface> &, const Standard_Boolean, const Standard_Real)) &BRepBuilderAPI_MakeFace::Init, "Initializes (or reinitializes) the construction of a face on the surface S. If Bound is true, a wire is automatically created from the natural bounds of the surface S and added to the face in order to bound it. If Bound is false, no wire is added. This option is used when real bounds are known. These will be added to the face after this initialization, using the function Add. TolDegen parameter is used for resolution of degenerated edges if calculation of natural bounds is turned on.", py::arg("S"), py::arg("Bound"), py::arg("TolDegen"));
cls_BRepBuilderAPI_MakeFace.def("Init", (void (BRepBuilderAPI_MakeFace::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepBuilderAPI_MakeFace::Init, "Initializes (or reinitializes) the construction of a face on the surface S, limited in the u parametric direction by the two parameter values UMin and UMax and in the v parametric direction by the two parameter values VMin and VMax. Warning Error returns: - BRepBuilderAPI_ParametersOutOfRange when the parameters given are outside the bounds of the surface or the basis surface of a trimmed surface. TolDegen parameter is used for resolution of degenerated edges.", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("TolDegen"));
cls_BRepBuilderAPI_MakeFace.def("Add", (void (BRepBuilderAPI_MakeFace::*)(const TopoDS_Wire &)) &BRepBuilderAPI_MakeFace::Add, "Adds the wire W to the constructed face as a hole. Warning W must not cross the other bounds of the face, and all the bounds must define only one area on the surface. (Be careful, however, as this is not checked.) Example // a cylinder gp_Cylinder C = ..; // a wire TopoDS_Wire W = ...; BRepBuilderAPI_MakeFace MF(C); MF.Add(W); TopoDS_Face F = MF;", py::arg("W"));
cls_BRepBuilderAPI_MakeFace.def("IsDone", (Standard_Boolean (BRepBuilderAPI_MakeFace::*)() const) &BRepBuilderAPI_MakeFace::IsDone, "Returns true if this algorithm has a valid face.");
cls_BRepBuilderAPI_MakeFace.def("Error", (BRepBuilderAPI_FaceError (BRepBuilderAPI_MakeFace::*)() const) &BRepBuilderAPI_MakeFace::Error, "Returns the construction status BRepBuilderAPI_FaceDone if the face is built, or - another value of the BRepBuilderAPI_FaceError enumeration indicating why the construction failed, in particular when the given parameters are outside the bounds of the surface.");
cls_BRepBuilderAPI_MakeFace.def("Face", (const TopoDS_Face & (BRepBuilderAPI_MakeFace::*)() const) &BRepBuilderAPI_MakeFace::Face, "Returns the constructed face. Exceptions StdFail_NotDone if no face is built.");

// Enums

}