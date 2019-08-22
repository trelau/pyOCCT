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
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <BRepLib_FindSurface.hxx>

void bind_BRepLib_FindSurface(py::module &mod){

py::class_<BRepLib_FindSurface> cls_BRepLib_FindSurface(mod, "BRepLib_FindSurface", "Provides an algorithm to find a Surface through a set of edges.");

// Constructors
cls_BRepLib_FindSurface.def(py::init<>());
cls_BRepLib_FindSurface.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_BRepLib_FindSurface.def(py::init<const TopoDS_Shape &, const Standard_Real>(), py::arg("S"), py::arg("Tol"));
cls_BRepLib_FindSurface.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("Tol"), py::arg("OnlyPlane"));
cls_BRepLib_FindSurface.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("Tol"), py::arg("OnlyPlane"), py::arg("OnlyClosed"));

// Fields

// Methods
// cls_BRepLib_FindSurface.def_static("operator new_", (void * (*)(size_t)) &BRepLib_FindSurface::operator new, "None", py::arg("theSize"));
// cls_BRepLib_FindSurface.def_static("operator delete_", (void (*)(void *)) &BRepLib_FindSurface::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_FindSurface.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_FindSurface::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_FindSurface.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_FindSurface::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_FindSurface.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_FindSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_FindSurface.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_FindSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_FindSurface.def("Init", [](BRepLib_FindSurface &self, const TopoDS_Shape & a0) -> void { return self.Init(a0); });
cls_BRepLib_FindSurface.def("Init", [](BRepLib_FindSurface &self, const TopoDS_Shape & a0, const Standard_Real a1) -> void { return self.Init(a0, a1); });
cls_BRepLib_FindSurface.def("Init", [](BRepLib_FindSurface &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Boolean a2) -> void { return self.Init(a0, a1, a2); });
cls_BRepLib_FindSurface.def("Init", (void (BRepLib_FindSurface::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &BRepLib_FindSurface::Init, "Computes the Surface from the edges of <S> with the given tolerance. if <OnlyPlane> is true, the computed surface will be a plane. If it is not possible to find a plane, the flag NotDone will be set. If <OnlyClosed> is true, then S sould be a wire and the existing surface, on which wire S is not closed in 2D, will be ignored.", py::arg("S"), py::arg("Tol"), py::arg("OnlyPlane"), py::arg("OnlyClosed"));
cls_BRepLib_FindSurface.def("Found", (Standard_Boolean (BRepLib_FindSurface::*)() const) &BRepLib_FindSurface::Found, "None");
cls_BRepLib_FindSurface.def("Surface", (opencascade::handle<Geom_Surface> (BRepLib_FindSurface::*)() const) &BRepLib_FindSurface::Surface, "None");
cls_BRepLib_FindSurface.def("Tolerance", (Standard_Real (BRepLib_FindSurface::*)() const) &BRepLib_FindSurface::Tolerance, "None");
cls_BRepLib_FindSurface.def("ToleranceReached", (Standard_Real (BRepLib_FindSurface::*)() const) &BRepLib_FindSurface::ToleranceReached, "None");
cls_BRepLib_FindSurface.def("Existed", (Standard_Boolean (BRepLib_FindSurface::*)() const) &BRepLib_FindSurface::Existed, "None");
cls_BRepLib_FindSurface.def("Location", (TopLoc_Location (BRepLib_FindSurface::*)() const) &BRepLib_FindSurface::Location, "None");

// Enums

}