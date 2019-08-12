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

void bind_IGESAppli(py::module &);
void bind_IGESAppli_Node(py::module &);
void bind_IGESAppli_Array1OfNode(py::module &);
void bind_IGESAppli_HArray1OfNode(py::module &);
void bind_IGESAppli_FiniteElement(py::module &);
void bind_IGESAppli_Array1OfFiniteElement(py::module &);
void bind_IGESAppli_Flow(py::module &);
void bind_IGESAppli_Array1OfFlow(py::module &);
void bind_IGESAppli_DrilledHole(py::module &);
void bind_IGESAppli_HArray1OfFiniteElement(py::module &);
void bind_IGESAppli_ElementResults(py::module &);
void bind_IGESAppli_FlowLineSpec(py::module &);
void bind_IGESAppli_GeneralModule(py::module &);
void bind_IGESAppli_HArray1OfFlow(py::module &);
void bind_IGESAppli_LevelFunction(py::module &);
void bind_IGESAppli_LevelToPWBLayerMap(py::module &);
void bind_IGESAppli_LineWidening(py::module &);
void bind_IGESAppli_NodalConstraint(py::module &);
void bind_IGESAppli_NodalDisplAndRot(py::module &);
void bind_IGESAppli_NodalResults(py::module &);
void bind_IGESAppli_PartNumber(py::module &);
void bind_IGESAppli_PinNumber(py::module &);
void bind_IGESAppli_PipingFlow(py::module &);
void bind_IGESAppli_Protocol(py::module &);
void bind_IGESAppli_PWBArtworkStackup(py::module &);
void bind_IGESAppli_PWBDrilledHole(py::module &);
void bind_IGESAppli_ReadWriteModule(py::module &);
void bind_IGESAppli_ReferenceDesignator(py::module &);
void bind_IGESAppli_RegionRestriction(py::module &);
void bind_IGESAppli_SpecificModule(py::module &);
void bind_IGESAppli_ToolDrilledHole(py::module &);
void bind_IGESAppli_ToolElementResults(py::module &);
void bind_IGESAppli_ToolFiniteElement(py::module &);
void bind_IGESAppli_ToolFlow(py::module &);
void bind_IGESAppli_ToolFlowLineSpec(py::module &);
void bind_IGESAppli_ToolLevelFunction(py::module &);
void bind_IGESAppli_ToolLevelToPWBLayerMap(py::module &);
void bind_IGESAppli_ToolLineWidening(py::module &);
void bind_IGESAppli_ToolNodalConstraint(py::module &);
void bind_IGESAppli_ToolNodalDisplAndRot(py::module &);
void bind_IGESAppli_ToolNodalResults(py::module &);
void bind_IGESAppli_ToolNode(py::module &);
void bind_IGESAppli_ToolPartNumber(py::module &);
void bind_IGESAppli_ToolPinNumber(py::module &);
void bind_IGESAppli_ToolPipingFlow(py::module &);
void bind_IGESAppli_ToolPWBArtworkStackup(py::module &);
void bind_IGESAppli_ToolPWBDrilledHole(py::module &);
void bind_IGESAppli_ToolReferenceDesignator(py::module &);
void bind_IGESAppli_ToolRegionRestriction(py::module &);

PYBIND11_MODULE(IGESAppli, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.IGESData");
py::module::import("OCCT.gp");
py::module::import("OCCT.IGESGeom");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.IGESDraw");
py::module::import("OCCT.Interface");
py::module::import("OCCT.IGESGraph");
py::module::import("OCCT.IGESDimen");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.IGESBasic");
py::module::import("OCCT.IGESDefs");
py::module::import("OCCT.Message");

bind_IGESAppli(mod);
bind_IGESAppli_Node(mod);
bind_IGESAppli_Array1OfNode(mod);
bind_IGESAppli_HArray1OfNode(mod);
bind_IGESAppli_FiniteElement(mod);
bind_IGESAppli_Array1OfFiniteElement(mod);
bind_IGESAppli_Flow(mod);
bind_IGESAppli_Array1OfFlow(mod);
bind_IGESAppli_DrilledHole(mod);
bind_IGESAppli_HArray1OfFiniteElement(mod);
bind_IGESAppli_ElementResults(mod);
bind_IGESAppli_FlowLineSpec(mod);
bind_IGESAppli_GeneralModule(mod);
bind_IGESAppli_HArray1OfFlow(mod);
bind_IGESAppli_LevelFunction(mod);
bind_IGESAppli_LevelToPWBLayerMap(mod);
bind_IGESAppli_LineWidening(mod);
bind_IGESAppli_NodalConstraint(mod);
bind_IGESAppli_NodalDisplAndRot(mod);
bind_IGESAppli_NodalResults(mod);
bind_IGESAppli_PartNumber(mod);
bind_IGESAppli_PinNumber(mod);
bind_IGESAppli_PipingFlow(mod);
bind_IGESAppli_Protocol(mod);
bind_IGESAppli_PWBArtworkStackup(mod);
bind_IGESAppli_PWBDrilledHole(mod);
bind_IGESAppli_ReadWriteModule(mod);
bind_IGESAppli_ReferenceDesignator(mod);
bind_IGESAppli_RegionRestriction(mod);
bind_IGESAppli_SpecificModule(mod);
bind_IGESAppli_ToolDrilledHole(mod);
bind_IGESAppli_ToolElementResults(mod);
bind_IGESAppli_ToolFiniteElement(mod);
bind_IGESAppli_ToolFlow(mod);
bind_IGESAppli_ToolFlowLineSpec(mod);
bind_IGESAppli_ToolLevelFunction(mod);
bind_IGESAppli_ToolLevelToPWBLayerMap(mod);
bind_IGESAppli_ToolLineWidening(mod);
bind_IGESAppli_ToolNodalConstraint(mod);
bind_IGESAppli_ToolNodalDisplAndRot(mod);
bind_IGESAppli_ToolNodalResults(mod);
bind_IGESAppli_ToolNode(mod);
bind_IGESAppli_ToolPartNumber(mod);
bind_IGESAppli_ToolPinNumber(mod);
bind_IGESAppli_ToolPipingFlow(mod);
bind_IGESAppli_ToolPWBArtworkStackup(mod);
bind_IGESAppli_ToolPWBDrilledHole(mod);
bind_IGESAppli_ToolReferenceDesignator(mod);
bind_IGESAppli_ToolRegionRestriction(mod);

}
