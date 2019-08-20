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
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <TopTools_OrientedShapeMapHasher.hxx>
#include <TopTools_LocationSet.hxx>
#include <TopTools_ShapeSet.hxx>
#include <TopTools.hxx>

void bind_TopTools(py::module &mod){

py::class_<TopTools, std::unique_ptr<TopTools>> cls_TopTools(mod, "TopTools", "The TopTools package provides utilities for the topological data structure.");

// Constructors

// Fields

// Methods
// cls_TopTools.def_static("operator new_", (void * (*)(size_t)) &TopTools::operator new, "None", py::arg("theSize"));
// cls_TopTools.def_static("operator delete_", (void (*)(void *)) &TopTools::operator delete, "None", py::arg("theAddress"));
// cls_TopTools.def_static("operator new[]_", (void * (*)(size_t)) &TopTools::operator new[], "None", py::arg("theSize"));
// cls_TopTools.def_static("operator delete[]_", (void (*)(void *)) &TopTools::operator delete[], "None", py::arg("theAddress"));
// cls_TopTools.def_static("operator new_", (void * (*)(size_t, void *)) &TopTools::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopTools.def_static("operator delete_", (void (*)(void *, void *)) &TopTools::operator delete, "None", py::arg(""), py::arg(""));
cls_TopTools.def_static("Dump_", (void (*)(const TopoDS_Shape &, Standard_OStream &)) &TopTools::Dump, "A set of Shapes. Can be dump, wrote or read. Dumps the topological structure of <Sh> on the stream <S>.", py::arg("Sh"), py::arg("S"));
cls_TopTools.def_static("Dummy_", (void (*)(const Standard_Integer)) &TopTools::Dummy, "This is to bypass an extraction bug. It will force the inclusion of Standard_Integer.hxx itself including Standard_OStream.hxx at the correct position.", py::arg("I"));

// Enums

}