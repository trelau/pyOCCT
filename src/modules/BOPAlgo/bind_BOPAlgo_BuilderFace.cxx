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
#include <BOPAlgo_BuilderArea.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <TopoDS_Face.hxx>
#include <TopAbs_Orientation.hxx>
#include <BOPAlgo_BuilderFace.hxx>

void bind_BOPAlgo_BuilderFace(py::module &mod){

py::class_<BOPAlgo_BuilderFace, BOPAlgo_BuilderArea> cls_BOPAlgo_BuilderFace(mod, "BOPAlgo_BuilderFace", "The algorithm to build new faces from the given faces and set of edges lying on this face.");

// Constructors
cls_BOPAlgo_BuilderFace.def(py::init<>());
cls_BOPAlgo_BuilderFace.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPAlgo_BuilderFace.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_BuilderFace::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_BuilderFace.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_BuilderFace::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_BuilderFace.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_BuilderFace::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_BuilderFace.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_BuilderFace::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_BuilderFace.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_BuilderFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_BuilderFace.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_BuilderFace::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_BuilderFace.def("SetFace", (void (BOPAlgo_BuilderFace::*)(const TopoDS_Face &)) &BOPAlgo_BuilderFace::SetFace, "Sets the face generatix", py::arg("theFace"));
cls_BOPAlgo_BuilderFace.def("Face", (const TopoDS_Face & (BOPAlgo_BuilderFace::*)() const) &BOPAlgo_BuilderFace::Face, "Returns the face generatix");
cls_BOPAlgo_BuilderFace.def("Perform", (void (BOPAlgo_BuilderFace::*)()) &BOPAlgo_BuilderFace::Perform, "Performs the algorithm");
cls_BOPAlgo_BuilderFace.def("Orientation", (TopAbs_Orientation (BOPAlgo_BuilderFace::*)() const) &BOPAlgo_BuilderFace::Orientation, "None");

// Enums

}