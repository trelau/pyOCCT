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

void bind_IGESBasic(py::module &);
void bind_IGESBasic_Array1OfLineFontEntity(py::module &);
void bind_IGESBasic_Array2OfHArray1OfReal(py::module &);
void bind_IGESBasic_AssocGroupType(py::module &);
void bind_IGESBasic_ExternalReferenceFile(py::module &);
void bind_IGESBasic_ExternalRefFile(py::module &);
void bind_IGESBasic_ExternalRefFileIndex(py::module &);
void bind_IGESBasic_ExternalRefFileName(py::module &);
void bind_IGESBasic_ExternalRefLibName(py::module &);
void bind_IGESBasic_ExternalRefName(py::module &);
void bind_IGESBasic_GeneralModule(py::module &);
void bind_IGESBasic_Group(py::module &);
void bind_IGESBasic_GroupWithoutBackP(py::module &);
void bind_IGESBasic_HArray1OfHArray1OfIGESEntity(py::module &);
void bind_IGESBasic_HArray1OfHArray1OfInteger(py::module &);
void bind_IGESBasic_HArray1OfHArray1OfReal(py::module &);
void bind_IGESBasic_HArray1OfHArray1OfXY(py::module &);
void bind_IGESBasic_HArray1OfHArray1OfXYZ(py::module &);
void bind_IGESBasic_HArray1OfLineFontEntity(py::module &);
void bind_IGESBasic_HArray2OfHArray1OfReal(py::module &);
void bind_IGESBasic_Hierarchy(py::module &);
void bind_IGESBasic_Name(py::module &);
void bind_IGESBasic_OrderedGroup(py::module &);
void bind_IGESBasic_OrderedGroupWithoutBackP(py::module &);
void bind_IGESBasic_Protocol(py::module &);
void bind_IGESBasic_ReadWriteModule(py::module &);
void bind_IGESBasic_SingleParent(py::module &);
void bind_IGESBasic_SingularSubfigure(py::module &);
void bind_IGESBasic_SpecificModule(py::module &);
void bind_IGESBasic_SubfigureDef(py::module &);
void bind_IGESBasic_ToolAssocGroupType(py::module &);
void bind_IGESBasic_ToolExternalReferenceFile(py::module &);
void bind_IGESBasic_ToolExternalRefFile(py::module &);
void bind_IGESBasic_ToolExternalRefFileIndex(py::module &);
void bind_IGESBasic_ToolExternalRefFileName(py::module &);
void bind_IGESBasic_ToolExternalRefLibName(py::module &);
void bind_IGESBasic_ToolExternalRefName(py::module &);
void bind_IGESBasic_ToolGroup(py::module &);
void bind_IGESBasic_ToolGroupWithoutBackP(py::module &);
void bind_IGESBasic_ToolHierarchy(py::module &);
void bind_IGESBasic_ToolName(py::module &);
void bind_IGESBasic_ToolOrderedGroup(py::module &);
void bind_IGESBasic_ToolOrderedGroupWithoutBackP(py::module &);
void bind_IGESBasic_ToolSingleParent(py::module &);
void bind_IGESBasic_ToolSingularSubfigure(py::module &);
void bind_IGESBasic_ToolSubfigureDef(py::module &);

PYBIND11_MODULE(IGESBasic, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.IGESData");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.Interface");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.gp");
py::module::import("OCCT.Message");

bind_IGESBasic(mod);
bind_IGESBasic_Array1OfLineFontEntity(mod);
bind_IGESBasic_Array2OfHArray1OfReal(mod);
bind_IGESBasic_AssocGroupType(mod);
bind_IGESBasic_ExternalReferenceFile(mod);
bind_IGESBasic_ExternalRefFile(mod);
bind_IGESBasic_ExternalRefFileIndex(mod);
bind_IGESBasic_ExternalRefFileName(mod);
bind_IGESBasic_ExternalRefLibName(mod);
bind_IGESBasic_ExternalRefName(mod);
bind_IGESBasic_GeneralModule(mod);
bind_IGESBasic_Group(mod);
bind_IGESBasic_GroupWithoutBackP(mod);
bind_IGESBasic_HArray1OfHArray1OfIGESEntity(mod);
bind_IGESBasic_HArray1OfHArray1OfInteger(mod);
bind_IGESBasic_HArray1OfHArray1OfReal(mod);
bind_IGESBasic_HArray1OfHArray1OfXY(mod);
bind_IGESBasic_HArray1OfHArray1OfXYZ(mod);
bind_IGESBasic_HArray1OfLineFontEntity(mod);
bind_IGESBasic_HArray2OfHArray1OfReal(mod);
bind_IGESBasic_Hierarchy(mod);
bind_IGESBasic_Name(mod);
bind_IGESBasic_OrderedGroup(mod);
bind_IGESBasic_OrderedGroupWithoutBackP(mod);
bind_IGESBasic_Protocol(mod);
bind_IGESBasic_ReadWriteModule(mod);
bind_IGESBasic_SingleParent(mod);
bind_IGESBasic_SingularSubfigure(mod);
bind_IGESBasic_SpecificModule(mod);
bind_IGESBasic_SubfigureDef(mod);
bind_IGESBasic_ToolAssocGroupType(mod);
bind_IGESBasic_ToolExternalReferenceFile(mod);
bind_IGESBasic_ToolExternalRefFile(mod);
bind_IGESBasic_ToolExternalRefFileIndex(mod);
bind_IGESBasic_ToolExternalRefFileName(mod);
bind_IGESBasic_ToolExternalRefLibName(mod);
bind_IGESBasic_ToolExternalRefName(mod);
bind_IGESBasic_ToolGroup(mod);
bind_IGESBasic_ToolGroupWithoutBackP(mod);
bind_IGESBasic_ToolHierarchy(mod);
bind_IGESBasic_ToolName(mod);
bind_IGESBasic_ToolOrderedGroup(mod);
bind_IGESBasic_ToolOrderedGroupWithoutBackP(mod);
bind_IGESBasic_ToolSingleParent(mod);
bind_IGESBasic_ToolSingularSubfigure(mod);
bind_IGESBasic_ToolSubfigureDef(mod);

}
