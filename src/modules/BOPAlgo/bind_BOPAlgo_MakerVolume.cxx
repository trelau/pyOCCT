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
#include <BOPAlgo_Builder.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Solid.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BOPAlgo_PaveFiller.hxx>
#include <TopTools_MapOfShape.hxx>
#include <Bnd_Box.hxx>
#include <BOPAlgo_MakerVolume.hxx>

void bind_BOPAlgo_MakerVolume(py::module &mod){

py::class_<BOPAlgo_MakerVolume, std::unique_ptr<BOPAlgo_MakerVolume>, BOPAlgo_Builder> cls_BOPAlgo_MakerVolume(mod, "BOPAlgo_MakerVolume", "The algorithm is to build solids from set of shapes. It uses the BOPAlgo_Builder algorithm to intersect the given shapes and build the images of faces (if needed) and BOPAlgo_BuilderSolid algorithm to build the solids.");

// Constructors
cls_BOPAlgo_MakerVolume.def(py::init<>());
cls_BOPAlgo_MakerVolume.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPAlgo_MakerVolume.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_MakerVolume::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_MakerVolume.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_MakerVolume::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_MakerVolume.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_MakerVolume::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_MakerVolume.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_MakerVolume::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_MakerVolume.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_MakerVolume::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_MakerVolume.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_MakerVolume::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_MakerVolume.def("Clear", (void (BOPAlgo_MakerVolume::*)()) &BOPAlgo_MakerVolume::Clear, "Clears the data.");
cls_BOPAlgo_MakerVolume.def("SetIntersect", (void (BOPAlgo_MakerVolume::*)(const Standard_Boolean)) &BOPAlgo_MakerVolume::SetIntersect, "Sets the flag myIntersect: if <bIntersect> is TRUE the shapes from <myArguments> will be intersected. if <bIntersect> is FALSE no intersection will be done.", py::arg("bIntersect"));
cls_BOPAlgo_MakerVolume.def("IsIntersect", (Standard_Boolean (BOPAlgo_MakerVolume::*)() const) &BOPAlgo_MakerVolume::IsIntersect, "Returns the flag <myIntersect>.");
cls_BOPAlgo_MakerVolume.def("Box", (const TopoDS_Solid & (BOPAlgo_MakerVolume::*)() const) &BOPAlgo_MakerVolume::Box, "Returns the solid box <mySBox>.");
cls_BOPAlgo_MakerVolume.def("Faces", (const TopTools_ListOfShape & (BOPAlgo_MakerVolume::*)() const) &BOPAlgo_MakerVolume::Faces, "Returns the processed faces <myFaces>.");
cls_BOPAlgo_MakerVolume.def("SetAvoidInternalShapes", (void (BOPAlgo_MakerVolume::*)(const Standard_Boolean)) &BOPAlgo_MakerVolume::SetAvoidInternalShapes, "Defines the preventing of addition of internal for solid parts into the result. By default the internal parts are added into result.", py::arg("theAvoidInternal"));
cls_BOPAlgo_MakerVolume.def("IsAvoidInternalShapes", (Standard_Boolean (BOPAlgo_MakerVolume::*)() const) &BOPAlgo_MakerVolume::IsAvoidInternalShapes, "Returns the AvoidInternalShapes flag");
cls_BOPAlgo_MakerVolume.def("Perform", (void (BOPAlgo_MakerVolume::*)()) &BOPAlgo_MakerVolume::Perform, "Performs the operation.");

// Enums

}