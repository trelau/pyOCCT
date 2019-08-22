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
#include <VrmlConverter_Projector.hxx>
#include <VrmlConverter_HLRShape.hxx>

void bind_VrmlConverter_HLRShape(py::module &mod){

py::class_<VrmlConverter_HLRShape> cls_VrmlConverter_HLRShape(mod, "VrmlConverter_HLRShape", "HLRShape - computes the presentation of objects with removal of their hidden lines for a specific projector, converts them into VRML objects and writes (adds) them into anOStream. All requested properties of the representation are specify in aDrawer of Drawer class. This kind of the presentation is converted into IndexedLineSet and if they are defined in Projector into : PerspectiveCamera, OrthographicCamera, DirectionLight, PointLight, SpotLight from Vrml package.");

// Constructors

// Fields

// Methods
// cls_VrmlConverter_HLRShape.def_static("operator new_", (void * (*)(size_t)) &VrmlConverter_HLRShape::operator new, "None", py::arg("theSize"));
// cls_VrmlConverter_HLRShape.def_static("operator delete_", (void (*)(void *)) &VrmlConverter_HLRShape::operator delete, "None", py::arg("theAddress"));
// cls_VrmlConverter_HLRShape.def_static("operator new[]_", (void * (*)(size_t)) &VrmlConverter_HLRShape::operator new[], "None", py::arg("theSize"));
// cls_VrmlConverter_HLRShape.def_static("operator delete[]_", (void (*)(void *)) &VrmlConverter_HLRShape::operator delete[], "None", py::arg("theAddress"));
// cls_VrmlConverter_HLRShape.def_static("operator new_", (void * (*)(size_t, void *)) &VrmlConverter_HLRShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_VrmlConverter_HLRShape.def_static("operator delete_", (void (*)(void *, void *)) &VrmlConverter_HLRShape::operator delete, "None", py::arg(""), py::arg(""));
cls_VrmlConverter_HLRShape.def_static("Add_", (void (*)(Standard_OStream &, const TopoDS_Shape &, const opencascade::handle<VrmlConverter_Drawer> &, const opencascade::handle<VrmlConverter_Projector> &)) &VrmlConverter_HLRShape::Add, "None", py::arg("anOStream"), py::arg("aShape"), py::arg("aDrawer"), py::arg("aProjector"));

// Enums

}