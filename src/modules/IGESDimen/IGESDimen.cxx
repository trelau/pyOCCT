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

void bind_IGESDimen_GeneralNote(py::module &);
void bind_IGESDimen_Array1OfGeneralNote(py::module &);
void bind_IGESDimen_HArray1OfGeneralNote(py::module &);
void bind_IGESDimen(py::module &);
void bind_IGESDimen_AngularDimension(py::module &);
void bind_IGESDimen_LeaderArrow(py::module &);
void bind_IGESDimen_Array1OfLeaderArrow(py::module &);
void bind_IGESDimen_BasicDimension(py::module &);
void bind_IGESDimen_CenterLine(py::module &);
void bind_IGESDimen_CurveDimension(py::module &);
void bind_IGESDimen_DiameterDimension(py::module &);
void bind_IGESDimen_DimensionDisplayData(py::module &);
void bind_IGESDimen_DimensionedGeometry(py::module &);
void bind_IGESDimen_DimensionTolerance(py::module &);
void bind_IGESDimen_DimensionUnits(py::module &);
void bind_IGESDimen_HArray1OfLeaderArrow(py::module &);
void bind_IGESDimen_FlagNote(py::module &);
void bind_IGESDimen_GeneralLabel(py::module &);
void bind_IGESDimen_GeneralModule(py::module &);
void bind_IGESDimen_GeneralSymbol(py::module &);
void bind_IGESDimen_LinearDimension(py::module &);
void bind_IGESDimen_NewDimensionedGeometry(py::module &);
void bind_IGESDimen_NewGeneralNote(py::module &);
void bind_IGESDimen_OrdinateDimension(py::module &);
void bind_IGESDimen_PointDimension(py::module &);
void bind_IGESDimen_Protocol(py::module &);
void bind_IGESDimen_RadiusDimension(py::module &);
void bind_IGESDimen_ReadWriteModule(py::module &);
void bind_IGESDimen_Section(py::module &);
void bind_IGESDimen_SectionedArea(py::module &);
void bind_IGESDimen_SpecificModule(py::module &);
void bind_IGESDimen_ToolAngularDimension(py::module &);
void bind_IGESDimen_ToolBasicDimension(py::module &);
void bind_IGESDimen_ToolCenterLine(py::module &);
void bind_IGESDimen_ToolCurveDimension(py::module &);
void bind_IGESDimen_ToolDiameterDimension(py::module &);
void bind_IGESDimen_ToolDimensionDisplayData(py::module &);
void bind_IGESDimen_ToolDimensionedGeometry(py::module &);
void bind_IGESDimen_ToolDimensionTolerance(py::module &);
void bind_IGESDimen_ToolDimensionUnits(py::module &);
void bind_IGESDimen_ToolFlagNote(py::module &);
void bind_IGESDimen_ToolGeneralLabel(py::module &);
void bind_IGESDimen_ToolGeneralNote(py::module &);
void bind_IGESDimen_ToolGeneralSymbol(py::module &);
void bind_IGESDimen_ToolLeaderArrow(py::module &);
void bind_IGESDimen_ToolLinearDimension(py::module &);
void bind_IGESDimen_ToolNewDimensionedGeometry(py::module &);
void bind_IGESDimen_ToolNewGeneralNote(py::module &);
void bind_IGESDimen_ToolOrdinateDimension(py::module &);
void bind_IGESDimen_ToolPointDimension(py::module &);
void bind_IGESDimen_ToolRadiusDimension(py::module &);
void bind_IGESDimen_ToolSection(py::module &);
void bind_IGESDimen_ToolSectionedArea(py::module &);
void bind_IGESDimen_ToolWitnessLine(py::module &);
void bind_IGESDimen_WitnessLine(py::module &);

PYBIND11_MODULE(IGESDimen, mod) {

py::module::import("OCCT.IGESData");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.IGESGraph");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Interface");
py::module::import("OCCT.gp");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.IGESGeom");
py::module::import("OCCT.Message");

bind_IGESDimen_GeneralNote(mod);
bind_IGESDimen_Array1OfGeneralNote(mod);
bind_IGESDimen_HArray1OfGeneralNote(mod);
bind_IGESDimen(mod);
bind_IGESDimen_AngularDimension(mod);
bind_IGESDimen_LeaderArrow(mod);
bind_IGESDimen_Array1OfLeaderArrow(mod);
bind_IGESDimen_BasicDimension(mod);
bind_IGESDimen_CenterLine(mod);
bind_IGESDimen_CurveDimension(mod);
bind_IGESDimen_DiameterDimension(mod);
bind_IGESDimen_DimensionDisplayData(mod);
bind_IGESDimen_DimensionedGeometry(mod);
bind_IGESDimen_DimensionTolerance(mod);
bind_IGESDimen_DimensionUnits(mod);
bind_IGESDimen_HArray1OfLeaderArrow(mod);
bind_IGESDimen_FlagNote(mod);
bind_IGESDimen_GeneralLabel(mod);
bind_IGESDimen_GeneralModule(mod);
bind_IGESDimen_GeneralSymbol(mod);
bind_IGESDimen_LinearDimension(mod);
bind_IGESDimen_NewDimensionedGeometry(mod);
bind_IGESDimen_NewGeneralNote(mod);
bind_IGESDimen_OrdinateDimension(mod);
bind_IGESDimen_PointDimension(mod);
bind_IGESDimen_Protocol(mod);
bind_IGESDimen_RadiusDimension(mod);
bind_IGESDimen_ReadWriteModule(mod);
bind_IGESDimen_Section(mod);
bind_IGESDimen_SectionedArea(mod);
bind_IGESDimen_SpecificModule(mod);
bind_IGESDimen_ToolAngularDimension(mod);
bind_IGESDimen_ToolBasicDimension(mod);
bind_IGESDimen_ToolCenterLine(mod);
bind_IGESDimen_ToolCurveDimension(mod);
bind_IGESDimen_ToolDiameterDimension(mod);
bind_IGESDimen_ToolDimensionDisplayData(mod);
bind_IGESDimen_ToolDimensionedGeometry(mod);
bind_IGESDimen_ToolDimensionTolerance(mod);
bind_IGESDimen_ToolDimensionUnits(mod);
bind_IGESDimen_ToolFlagNote(mod);
bind_IGESDimen_ToolGeneralLabel(mod);
bind_IGESDimen_ToolGeneralNote(mod);
bind_IGESDimen_ToolGeneralSymbol(mod);
bind_IGESDimen_ToolLeaderArrow(mod);
bind_IGESDimen_ToolLinearDimension(mod);
bind_IGESDimen_ToolNewDimensionedGeometry(mod);
bind_IGESDimen_ToolNewGeneralNote(mod);
bind_IGESDimen_ToolOrdinateDimension(mod);
bind_IGESDimen_ToolPointDimension(mod);
bind_IGESDimen_ToolRadiusDimension(mod);
bind_IGESDimen_ToolSection(mod);
bind_IGESDimen_ToolSectionedArea(mod);
bind_IGESDimen_ToolWitnessLine(mod);
bind_IGESDimen_WitnessLine(mod);

}
