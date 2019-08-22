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
#include <Standard_OStream.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <VrmlConverter_Drawer.hxx>
#include <VrmlConverter_WFShape.hxx>

void bind_VrmlConverter_WFShape(py::module &mod){

py::class_<VrmlConverter_WFShape> cls_VrmlConverter_WFShape(mod, "VrmlConverter_WFShape", "WFShape - computes the wireframe presentation of compound set of faces, edges and vertices by displaying a given number of U and/or V isoparametric curves converts this one into VRML objects and writes (adds) them into anOStream. All requested properties of the representation are specify in aDrawer. This kind of the presentation is converted into IndexedLineSet and PointSet ( VRML ).");

// Constructors

// Fields

// Methods
// cls_VrmlConverter_WFShape.def_static("operator new_", (void * (*)(size_t)) &VrmlConverter_WFShape::operator new, "None", py::arg("theSize"));
// cls_VrmlConverter_WFShape.def_static("operator delete_", (void (*)(void *)) &VrmlConverter_WFShape::operator delete, "None", py::arg("theAddress"));
// cls_VrmlConverter_WFShape.def_static("operator new[]_", (void * (*)(size_t)) &VrmlConverter_WFShape::operator new[], "None", py::arg("theSize"));
// cls_VrmlConverter_WFShape.def_static("operator delete[]_", (void (*)(void *)) &VrmlConverter_WFShape::operator delete[], "None", py::arg("theAddress"));
// cls_VrmlConverter_WFShape.def_static("operator new_", (void * (*)(size_t, void *)) &VrmlConverter_WFShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_VrmlConverter_WFShape.def_static("operator delete_", (void (*)(void *, void *)) &VrmlConverter_WFShape::operator delete, "None", py::arg(""), py::arg(""));
cls_VrmlConverter_WFShape.def_static("Add_", (void (*)(Standard_OStream &, const TopoDS_Shape &, const opencascade::handle<VrmlConverter_Drawer> &)) &VrmlConverter_WFShape::Add, "None", py::arg("anOStream"), py::arg("aShape"), py::arg("aDrawer"));

// Enums

}