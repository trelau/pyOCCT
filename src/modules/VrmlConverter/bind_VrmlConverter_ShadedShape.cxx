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
#include <TopoDS_Face.hxx>
#include <Poly_Connect.hxx>
#include <TColgp_Array1OfDir.hxx>
#include <VrmlConverter_ShadedShape.hxx>

void bind_VrmlConverter_ShadedShape(py::module &mod){

py::class_<VrmlConverter_ShadedShape> cls_VrmlConverter_ShadedShape(mod, "VrmlConverter_ShadedShape", "ShadedShape - computes the shading presentation of shapes by triangulation algorithms, converts this one into VRML objects and writes (adds) into anOStream. All requested properties of the representation including the maximal chordial deviation are specify in aDrawer. This kind of the presentation is converted into IndexedFaceSet ( VRML ).");

// Constructors

// Fields

// Methods
// cls_VrmlConverter_ShadedShape.def_static("operator new_", (void * (*)(size_t)) &VrmlConverter_ShadedShape::operator new, "None", py::arg("theSize"));
// cls_VrmlConverter_ShadedShape.def_static("operator delete_", (void (*)(void *)) &VrmlConverter_ShadedShape::operator delete, "None", py::arg("theAddress"));
// cls_VrmlConverter_ShadedShape.def_static("operator new[]_", (void * (*)(size_t)) &VrmlConverter_ShadedShape::operator new[], "None", py::arg("theSize"));
// cls_VrmlConverter_ShadedShape.def_static("operator delete[]_", (void (*)(void *)) &VrmlConverter_ShadedShape::operator delete[], "None", py::arg("theAddress"));
// cls_VrmlConverter_ShadedShape.def_static("operator new_", (void * (*)(size_t, void *)) &VrmlConverter_ShadedShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_VrmlConverter_ShadedShape.def_static("operator delete_", (void (*)(void *, void *)) &VrmlConverter_ShadedShape::operator delete, "None", py::arg(""), py::arg(""));
cls_VrmlConverter_ShadedShape.def_static("Add_", (void (*)(Standard_OStream &, const TopoDS_Shape &, const opencascade::handle<VrmlConverter_Drawer> &)) &VrmlConverter_ShadedShape::Add, "None", py::arg("anOStream"), py::arg("aShape"), py::arg("aDrawer"));
cls_VrmlConverter_ShadedShape.def_static("ComputeNormal_", (void (*)(const TopoDS_Face &, Poly_Connect &, TColgp_Array1OfDir &)) &VrmlConverter_ShadedShape::ComputeNormal, "None", py::arg("aFace"), py::arg("pc"), py::arg("Nor"));

// Enums

}