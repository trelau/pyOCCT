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
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_Surface.hxx>

void bind_TopOpeBRepDS_Surface(py::module &mod){

py::class_<TopOpeBRepDS_Surface, std::unique_ptr<TopOpeBRepDS_Surface, Deleter<TopOpeBRepDS_Surface>>> cls_TopOpeBRepDS_Surface(mod, "TopOpeBRepDS_Surface", "A Geom surface and a tolerance.");

// Constructors
cls_TopOpeBRepDS_Surface.def(py::init<>());
cls_TopOpeBRepDS_Surface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("P"), py::arg("T"));
cls_TopOpeBRepDS_Surface.def(py::init<const TopOpeBRepDS_Surface &>(), py::arg("Other"));

// Fields

// Methods
// cls_TopOpeBRepDS_Surface.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_Surface::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Surface.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_Surface::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Surface.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_Surface::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Surface.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_Surface::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Surface.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_Surface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_Surface.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_Surface::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_Surface.def("Assign", (void (TopOpeBRepDS_Surface::*)(const TopOpeBRepDS_Surface &)) &TopOpeBRepDS_Surface::Assign, "None", py::arg("Other"));
// cls_TopOpeBRepDS_Surface.def("operator=", (void (TopOpeBRepDS_Surface::*)(const TopOpeBRepDS_Surface &)) &TopOpeBRepDS_Surface::operator=, "None", py::arg("Other"));
cls_TopOpeBRepDS_Surface.def("Surface", (const opencascade::handle<Geom_Surface> & (TopOpeBRepDS_Surface::*)() const) &TopOpeBRepDS_Surface::Surface, "None");
cls_TopOpeBRepDS_Surface.def("Tolerance", (Standard_Real (TopOpeBRepDS_Surface::*)() const) &TopOpeBRepDS_Surface::Tolerance, "None");
cls_TopOpeBRepDS_Surface.def("Tolerance", (void (TopOpeBRepDS_Surface::*)(const Standard_Real)) &TopOpeBRepDS_Surface::Tolerance, "Update the tolerance", py::arg("tol"));
cls_TopOpeBRepDS_Surface.def("Keep", (Standard_Boolean (TopOpeBRepDS_Surface::*)() const) &TopOpeBRepDS_Surface::Keep, "None");
cls_TopOpeBRepDS_Surface.def("ChangeKeep", (void (TopOpeBRepDS_Surface::*)(const Standard_Boolean)) &TopOpeBRepDS_Surface::ChangeKeep, "None", py::arg("B"));

// Enums

}