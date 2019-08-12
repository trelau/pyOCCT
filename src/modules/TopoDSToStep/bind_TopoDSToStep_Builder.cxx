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
#include <TopoDSToStep_Root.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDSToStep_Tool.hxx>
#include <Standard_Handle.hxx>
#include <Transfer_FinderProcess.hxx>
#include <TopoDSToStep_BuilderError.hxx>
#include <StepShape_TopologicalRepresentationItem.hxx>
#include <TopoDSToStep_Builder.hxx>

void bind_TopoDSToStep_Builder(py::module &mod){

py::class_<TopoDSToStep_Builder, std::unique_ptr<TopoDSToStep_Builder, Deleter<TopoDSToStep_Builder>>, TopoDSToStep_Root> cls_TopoDSToStep_Builder(mod, "TopoDSToStep_Builder", "This builder Class provides services to build a ProSTEP Shape model from a Cas.Cad BRep.");

// Constructors
cls_TopoDSToStep_Builder.def(py::init<>());
cls_TopoDSToStep_Builder.def(py::init<const TopoDS_Shape &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("S"), py::arg("T"), py::arg("FP"));

// Fields

// Methods
// cls_TopoDSToStep_Builder.def_static("operator new_", (void * (*)(size_t)) &TopoDSToStep_Builder::operator new, "None", py::arg("theSize"));
// cls_TopoDSToStep_Builder.def_static("operator delete_", (void (*)(void *)) &TopoDSToStep_Builder::operator delete, "None", py::arg("theAddress"));
// cls_TopoDSToStep_Builder.def_static("operator new[]_", (void * (*)(size_t)) &TopoDSToStep_Builder::operator new[], "None", py::arg("theSize"));
// cls_TopoDSToStep_Builder.def_static("operator delete[]_", (void (*)(void *)) &TopoDSToStep_Builder::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDSToStep_Builder.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDSToStep_Builder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDSToStep_Builder.def_static("operator delete_", (void (*)(void *, void *)) &TopoDSToStep_Builder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopoDSToStep_Builder.def("Init", (void (TopoDSToStep_Builder::*)(const TopoDS_Shape &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &)) &TopoDSToStep_Builder::Init, "None", py::arg("S"), py::arg("T"), py::arg("FP"));
cls_TopoDSToStep_Builder.def("Error", (TopoDSToStep_BuilderError (TopoDSToStep_Builder::*)() const) &TopoDSToStep_Builder::Error, "None");
cls_TopoDSToStep_Builder.def("Value", (const opencascade::handle<StepShape_TopologicalRepresentationItem> & (TopoDSToStep_Builder::*)() const) &TopoDSToStep_Builder::Value, "None");

// Enums

}