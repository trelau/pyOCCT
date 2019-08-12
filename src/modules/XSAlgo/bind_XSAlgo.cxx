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
#include <XSAlgo_AlgoContainer.hxx>
#include <XSAlgo_ToolContainer.hxx>
#include <XSAlgo.hxx>

void bind_XSAlgo(py::module &mod){

py::class_<XSAlgo, std::unique_ptr<XSAlgo, Deleter<XSAlgo>>> cls_XSAlgo(mod, "XSAlgo", "None");

// Constructors

// Fields

// Methods
// cls_XSAlgo.def_static("operator new_", (void * (*)(size_t)) &XSAlgo::operator new, "None", py::arg("theSize"));
// cls_XSAlgo.def_static("operator delete_", (void (*)(void *)) &XSAlgo::operator delete, "None", py::arg("theAddress"));
// cls_XSAlgo.def_static("operator new[]_", (void * (*)(size_t)) &XSAlgo::operator new[], "None", py::arg("theSize"));
// cls_XSAlgo.def_static("operator delete[]_", (void (*)(void *)) &XSAlgo::operator delete[], "None", py::arg("theAddress"));
// cls_XSAlgo.def_static("operator new_", (void * (*)(size_t, void *)) &XSAlgo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XSAlgo.def_static("operator delete_", (void (*)(void *, void *)) &XSAlgo::operator delete, "None", py::arg(""), py::arg(""));
cls_XSAlgo.def_static("Init_", (void (*)()) &XSAlgo::Init, "Provides initerface to the algorithms from Shape Healing and others for XSTEP processors. Creates and initializes default AlgoContainer.");
cls_XSAlgo.def_static("SetAlgoContainer_", (void (*)(const opencascade::handle<XSAlgo_AlgoContainer> &)) &XSAlgo::SetAlgoContainer, "Sets default AlgoContainer", py::arg("aContainer"));
cls_XSAlgo.def_static("AlgoContainer_", (opencascade::handle<XSAlgo_AlgoContainer> (*)()) &XSAlgo::AlgoContainer, "Returns default AlgoContainer");

// Enums

}