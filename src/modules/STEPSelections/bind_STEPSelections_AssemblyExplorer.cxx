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
#include <Interface_Graph.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Handle.hxx>
#include <StepShape_ShapeDefinitionRepresentation.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <STEPSelections_AssemblyComponent.hxx>
#include <Standard_Transient.hxx>
#include <StepRepr_NextAssemblyUsageOccurrence.hxx>
#include <Standard_TypeDef.hxx>
#include <STEPSelections_SequenceOfAssemblyComponent.hxx>
#include <TColStd_IndexedDataMapOfTransientTransient.hxx>
#include <STEPSelections_AssemblyExplorer.hxx>

void bind_STEPSelections_AssemblyExplorer(py::module &mod){

py::class_<STEPSelections_AssemblyExplorer, std::unique_ptr<STEPSelections_AssemblyExplorer, Deleter<STEPSelections_AssemblyExplorer>>> cls_STEPSelections_AssemblyExplorer(mod, "STEPSelections_AssemblyExplorer", "None");

// Constructors
cls_STEPSelections_AssemblyExplorer.def(py::init<const Interface_Graph &>(), py::arg("G"));

// Fields

// Methods
// cls_STEPSelections_AssemblyExplorer.def_static("operator new_", (void * (*)(size_t)) &STEPSelections_AssemblyExplorer::operator new, "None", py::arg("theSize"));
// cls_STEPSelections_AssemblyExplorer.def_static("operator delete_", (void (*)(void *)) &STEPSelections_AssemblyExplorer::operator delete, "None", py::arg("theAddress"));
// cls_STEPSelections_AssemblyExplorer.def_static("operator new[]_", (void * (*)(size_t)) &STEPSelections_AssemblyExplorer::operator new[], "None", py::arg("theSize"));
// cls_STEPSelections_AssemblyExplorer.def_static("operator delete[]_", (void (*)(void *)) &STEPSelections_AssemblyExplorer::operator delete[], "None", py::arg("theAddress"));
// cls_STEPSelections_AssemblyExplorer.def_static("operator new_", (void * (*)(size_t, void *)) &STEPSelections_AssemblyExplorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPSelections_AssemblyExplorer.def_static("operator delete_", (void (*)(void *, void *)) &STEPSelections_AssemblyExplorer::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPSelections_AssemblyExplorer.def("Init", (void (STEPSelections_AssemblyExplorer::*)(const Interface_Graph &)) &STEPSelections_AssemblyExplorer::Init, "None", py::arg("G"));
cls_STEPSelections_AssemblyExplorer.def("Dump", (void (STEPSelections_AssemblyExplorer::*)(Standard_OStream &) const) &STEPSelections_AssemblyExplorer::Dump, "None", py::arg("os"));
cls_STEPSelections_AssemblyExplorer.def("FindSDRWithProduct", (opencascade::handle<StepShape_ShapeDefinitionRepresentation> (STEPSelections_AssemblyExplorer::*)(const opencascade::handle<StepBasic_ProductDefinition> &) const) &STEPSelections_AssemblyExplorer::FindSDRWithProduct, "None", py::arg("product"));
cls_STEPSelections_AssemblyExplorer.def("FillListWithGraph", (void (STEPSelections_AssemblyExplorer::*)(const opencascade::handle<STEPSelections_AssemblyComponent> &)) &STEPSelections_AssemblyExplorer::FillListWithGraph, "None", py::arg("cmp"));
cls_STEPSelections_AssemblyExplorer.def("FindItemWithNAUO", (opencascade::handle<Standard_Transient> (STEPSelections_AssemblyExplorer::*)(const opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> &) const) &STEPSelections_AssemblyExplorer::FindItemWithNAUO, "None", py::arg("nauo"));
cls_STEPSelections_AssemblyExplorer.def("NbAssemblies", (Standard_Integer (STEPSelections_AssemblyExplorer::*)() const) &STEPSelections_AssemblyExplorer::NbAssemblies, "Returns the number of root assemblies;");
cls_STEPSelections_AssemblyExplorer.def("Root", [](STEPSelections_AssemblyExplorer &self) -> opencascade::handle<STEPSelections_AssemblyComponent> { return self.Root(); });
cls_STEPSelections_AssemblyExplorer.def("Root", (opencascade::handle<STEPSelections_AssemblyComponent> (STEPSelections_AssemblyExplorer::*)(const Standard_Integer) const) &STEPSelections_AssemblyExplorer::Root, "Returns root of assenbly by its rank;", py::arg("rank"));

// Enums

}