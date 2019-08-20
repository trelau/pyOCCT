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
#include <Geom2dAdaptor_Curve.hxx>
#include <Standard.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <BRepAdaptor_Curve2d.hxx>

void bind_BRepAdaptor_Curve2d(py::module &mod){

py::class_<BRepAdaptor_Curve2d, std::unique_ptr<BRepAdaptor_Curve2d>, Geom2dAdaptor_Curve> cls_BRepAdaptor_Curve2d(mod, "BRepAdaptor_Curve2d", "The Curve2d from BRepAdaptor allows to use an Edge on a Face like a 2d curve. (curve in the parametric space).");

// Constructors
cls_BRepAdaptor_Curve2d.def(py::init<>());
cls_BRepAdaptor_Curve2d.def(py::init<const TopoDS_Edge &, const TopoDS_Face &>(), py::arg("E"), py::arg("F"));

// Fields

// Methods
// cls_BRepAdaptor_Curve2d.def_static("operator new_", (void * (*)(size_t)) &BRepAdaptor_Curve2d::operator new, "None", py::arg("theSize"));
// cls_BRepAdaptor_Curve2d.def_static("operator delete_", (void (*)(void *)) &BRepAdaptor_Curve2d::operator delete, "None", py::arg("theAddress"));
// cls_BRepAdaptor_Curve2d.def_static("operator new[]_", (void * (*)(size_t)) &BRepAdaptor_Curve2d::operator new[], "None", py::arg("theSize"));
// cls_BRepAdaptor_Curve2d.def_static("operator delete[]_", (void (*)(void *)) &BRepAdaptor_Curve2d::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAdaptor_Curve2d.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAdaptor_Curve2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAdaptor_Curve2d.def_static("operator delete_", (void (*)(void *, void *)) &BRepAdaptor_Curve2d::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAdaptor_Curve2d.def("Initialize", (void (BRepAdaptor_Curve2d::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepAdaptor_Curve2d::Initialize, "Initialize with the pcurve of <E> on <F>.", py::arg("E"), py::arg("F"));
cls_BRepAdaptor_Curve2d.def("Edge", (const TopoDS_Edge & (BRepAdaptor_Curve2d::*)() const) &BRepAdaptor_Curve2d::Edge, "Returns the Edge.");
cls_BRepAdaptor_Curve2d.def("Face", (const TopoDS_Face & (BRepAdaptor_Curve2d::*)() const) &BRepAdaptor_Curve2d::Face, "Returns the Face.");

// Enums

}