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
#include <IGESAppli_Protocol.hxx>
#include <IGESAppli_Node.hxx>
#include <IGESAppli_FiniteElement.hxx>
#include <IGESAppli_NodalDisplAndRot.hxx>
#include <IGESAppli_NodalResults.hxx>
#include <IGESAppli_ElementResults.hxx>
#include <IGESAppli_Flow.hxx>
#include <IGESAppli_PipingFlow.hxx>
#include <IGESAppli_RegionRestriction.hxx>
#include <IGESAppli_LevelFunction.hxx>
#include <IGESAppli_LineWidening.hxx>
#include <IGESAppli_DrilledHole.hxx>
#include <IGESAppli_ReferenceDesignator.hxx>
#include <IGESAppli_PinNumber.hxx>
#include <IGESAppli_PartNumber.hxx>
#include <IGESAppli_FlowLineSpec.hxx>
#include <IGESAppli_LevelToPWBLayerMap.hxx>
#include <IGESAppli_PWBArtworkStackup.hxx>
#include <IGESAppli_PWBDrilledHole.hxx>
#include <IGESAppli_NodalConstraint.hxx>
#include <IGESAppli_ToolNode.hxx>
#include <IGESAppli_ToolFiniteElement.hxx>
#include <IGESAppli_ToolNodalDisplAndRot.hxx>
#include <IGESAppli_ToolNodalResults.hxx>
#include <IGESAppli_ToolElementResults.hxx>
#include <IGESAppli_ToolFlow.hxx>
#include <IGESAppli_ToolPipingFlow.hxx>
#include <IGESAppli_ToolRegionRestriction.hxx>
#include <IGESAppli_ToolLevelFunction.hxx>
#include <IGESAppli_ToolLineWidening.hxx>
#include <IGESAppli_ToolDrilledHole.hxx>
#include <IGESAppli_ToolReferenceDesignator.hxx>
#include <IGESAppli_ToolPinNumber.hxx>
#include <IGESAppli_ToolPartNumber.hxx>
#include <IGESAppli_ToolFlowLineSpec.hxx>
#include <IGESAppli_ToolLevelToPWBLayerMap.hxx>
#include <IGESAppli_ToolPWBArtworkStackup.hxx>
#include <IGESAppli_ToolPWBDrilledHole.hxx>
#include <IGESAppli_ToolNodalConstraint.hxx>
#include <IGESAppli_ReadWriteModule.hxx>
#include <IGESAppli_GeneralModule.hxx>
#include <IGESAppli_SpecificModule.hxx>
#include <IGESAppli.hxx>

void bind_IGESAppli(py::module &mod){

py::class_<IGESAppli, std::unique_ptr<IGESAppli>> cls_IGESAppli(mod, "IGESAppli", "This package represents collection of miscellaneous entities from IGES");

// Constructors

// Fields

// Methods
// cls_IGESAppli.def_static("operator new_", (void * (*)(size_t)) &IGESAppli::operator new, "None", py::arg("theSize"));
// cls_IGESAppli.def_static("operator delete_", (void (*)(void *)) &IGESAppli::operator delete, "None", py::arg("theAddress"));
// cls_IGESAppli.def_static("operator new[]_", (void * (*)(size_t)) &IGESAppli::operator new[], "None", py::arg("theSize"));
// cls_IGESAppli.def_static("operator delete[]_", (void (*)(void *)) &IGESAppli::operator delete[], "None", py::arg("theAddress"));
// cls_IGESAppli.def_static("operator new_", (void * (*)(size_t, void *)) &IGESAppli::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESAppli.def_static("operator delete_", (void (*)(void *, void *)) &IGESAppli::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESAppli.def_static("Init_", (void (*)()) &IGESAppli::Init, "Prepares dynamic data (Protocol, Modules) for this package");
cls_IGESAppli.def_static("Protocol_", (opencascade::handle<IGESAppli_Protocol> (*)()) &IGESAppli::Protocol, "Returns the Protocol for this Package");

// Enums

}