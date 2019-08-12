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
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <BRepClass_Edge.hxx>

void bind_BRepClass_Edge(py::module &mod){

py::class_<BRepClass_Edge, std::unique_ptr<BRepClass_Edge, Deleter<BRepClass_Edge>>> cls_BRepClass_Edge(mod, "BRepClass_Edge", "This class is used to send the description of an Edge to the classifier. It contains an Edge and a Face. So the PCurve of the Edge can be found.");

// Constructors
cls_BRepClass_Edge.def(py::init<>());
cls_BRepClass_Edge.def(py::init<const TopoDS_Edge &, const TopoDS_Face &>(), py::arg("E"), py::arg("F"));

// Fields

// Methods
// cls_BRepClass_Edge.def_static("operator new_", (void * (*)(size_t)) &BRepClass_Edge::operator new, "None", py::arg("theSize"));
// cls_BRepClass_Edge.def_static("operator delete_", (void (*)(void *)) &BRepClass_Edge::operator delete, "None", py::arg("theAddress"));
// cls_BRepClass_Edge.def_static("operator new[]_", (void * (*)(size_t)) &BRepClass_Edge::operator new[], "None", py::arg("theSize"));
// cls_BRepClass_Edge.def_static("operator delete[]_", (void (*)(void *)) &BRepClass_Edge::operator delete[], "None", py::arg("theAddress"));
// cls_BRepClass_Edge.def_static("operator new_", (void * (*)(size_t, void *)) &BRepClass_Edge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepClass_Edge.def_static("operator delete_", (void (*)(void *, void *)) &BRepClass_Edge::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepClass_Edge.def("Edge", (TopoDS_Edge & (BRepClass_Edge::*)()) &BRepClass_Edge::Edge, "None");
cls_BRepClass_Edge.def("Edge", (const TopoDS_Edge & (BRepClass_Edge::*)() const) &BRepClass_Edge::Edge, "None");
cls_BRepClass_Edge.def("Face", (TopoDS_Face & (BRepClass_Edge::*)()) &BRepClass_Edge::Face, "None");
cls_BRepClass_Edge.def("Face", (const TopoDS_Face & (BRepClass_Edge::*)() const) &BRepClass_Edge::Face, "None");

// Enums

}