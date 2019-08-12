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

void bind_IGESSelect(py::module &);
void bind_IGESSelect_Activator(py::module &);
void bind_IGESSelect_FileModifier(py::module &);
void bind_IGESSelect_AddFileComment(py::module &);
void bind_IGESSelect_ModelModifier(py::module &);
void bind_IGESSelect_AddGroup(py::module &);
void bind_IGESSelect_AutoCorrect(py::module &);
void bind_IGESSelect_ChangeLevelList(py::module &);
void bind_IGESSelect_ChangeLevelNumber(py::module &);
void bind_IGESSelect_ComputeStatus(py::module &);
void bind_IGESSelect_CounterOfLevelNumber(py::module &);
void bind_IGESSelect_DispPerDrawing(py::module &);
void bind_IGESSelect_DispPerSingleView(py::module &);
void bind_IGESSelect_Dumper(py::module &);
void bind_IGESSelect_EditDirPart(py::module &);
void bind_IGESSelect_EditHeader(py::module &);
void bind_IGESSelect_FloatFormat(py::module &);
void bind_IGESSelect_IGESName(py::module &);
void bind_IGESSelect_IGESTypeForm(py::module &);
void bind_IGESSelect_RebuildDrawings(py::module &);
void bind_IGESSelect_RebuildGroups(py::module &);
void bind_IGESSelect_RemoveCurves(py::module &);
void bind_IGESSelect_SelectBasicGeom(py::module &);
void bind_IGESSelect_SelectBypassGroup(py::module &);
void bind_IGESSelect_SelectBypassSubfigure(py::module &);
void bind_IGESSelect_SelectDrawingFrom(py::module &);
void bind_IGESSelect_SelectFaces(py::module &);
void bind_IGESSelect_SelectFromDrawing(py::module &);
void bind_IGESSelect_SelectFromSingleView(py::module &);
void bind_IGESSelect_SelectLevelNumber(py::module &);
void bind_IGESSelect_SelectName(py::module &);
void bind_IGESSelect_SelectPCurves(py::module &);
void bind_IGESSelect_SelectSingleViewFrom(py::module &);
void bind_IGESSelect_SelectSubordinate(py::module &);
void bind_IGESSelect_SelectVisibleStatus(py::module &);
void bind_IGESSelect_SetGlobalParameter(py::module &);
void bind_IGESSelect_SetLabel(py::module &);
void bind_IGESSelect_SetVersion5(py::module &);
void bind_IGESSelect_SignColor(py::module &);
void bind_IGESSelect_SignLevelNumber(py::module &);
void bind_IGESSelect_SignStatus(py::module &);
void bind_IGESSelect_SplineToBSpline(py::module &);
void bind_IGESSelect_UpdateCreationDate(py::module &);
void bind_IGESSelect_UpdateFileName(py::module &);
void bind_IGESSelect_UpdateLastChange(py::module &);
void bind_IGESSelect_ViewSorter(py::module &);
void bind_IGESSelect_WorkLibrary(py::module &);

PYBIND11_MODULE(IGESSelect, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.IGESData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.IFSelect");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.Message");
py::module::import("OCCT.IFGraph");

bind_IGESSelect(mod);
bind_IGESSelect_Activator(mod);
bind_IGESSelect_FileModifier(mod);
bind_IGESSelect_AddFileComment(mod);
bind_IGESSelect_ModelModifier(mod);
bind_IGESSelect_AddGroup(mod);
bind_IGESSelect_AutoCorrect(mod);
bind_IGESSelect_ChangeLevelList(mod);
bind_IGESSelect_ChangeLevelNumber(mod);
bind_IGESSelect_ComputeStatus(mod);
bind_IGESSelect_CounterOfLevelNumber(mod);
bind_IGESSelect_DispPerDrawing(mod);
bind_IGESSelect_DispPerSingleView(mod);
bind_IGESSelect_Dumper(mod);
bind_IGESSelect_EditDirPart(mod);
bind_IGESSelect_EditHeader(mod);
bind_IGESSelect_FloatFormat(mod);
bind_IGESSelect_IGESName(mod);
bind_IGESSelect_IGESTypeForm(mod);
bind_IGESSelect_RebuildDrawings(mod);
bind_IGESSelect_RebuildGroups(mod);
bind_IGESSelect_RemoveCurves(mod);
bind_IGESSelect_SelectBasicGeom(mod);
bind_IGESSelect_SelectBypassGroup(mod);
bind_IGESSelect_SelectBypassSubfigure(mod);
bind_IGESSelect_SelectDrawingFrom(mod);
bind_IGESSelect_SelectFaces(mod);
bind_IGESSelect_SelectFromDrawing(mod);
bind_IGESSelect_SelectFromSingleView(mod);
bind_IGESSelect_SelectLevelNumber(mod);
bind_IGESSelect_SelectName(mod);
bind_IGESSelect_SelectPCurves(mod);
bind_IGESSelect_SelectSingleViewFrom(mod);
bind_IGESSelect_SelectSubordinate(mod);
bind_IGESSelect_SelectVisibleStatus(mod);
bind_IGESSelect_SetGlobalParameter(mod);
bind_IGESSelect_SetLabel(mod);
bind_IGESSelect_SetVersion5(mod);
bind_IGESSelect_SignColor(mod);
bind_IGESSelect_SignLevelNumber(mod);
bind_IGESSelect_SignStatus(mod);
bind_IGESSelect_SplineToBSpline(mod);
bind_IGESSelect_UpdateCreationDate(mod);
bind_IGESSelect_UpdateFileName(mod);
bind_IGESSelect_UpdateLastChange(mod);
bind_IGESSelect_ViewSorter(mod);
bind_IGESSelect_WorkLibrary(mod);

}
