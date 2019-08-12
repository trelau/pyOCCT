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

void bind_IGESDefs_TabularData(py::module &);
void bind_IGESDefs_Array1OfTabularData(py::module &);
void bind_IGESDefs_HArray1OfTabularData(py::module &);
void bind_IGESDefs(py::module &);
void bind_IGESDefs_AssociativityDef(py::module &);
void bind_IGESDefs_AttributeDef(py::module &);
void bind_IGESDefs_AttributeTable(py::module &);
void bind_IGESDefs_GeneralModule(py::module &);
void bind_IGESDefs_GenericData(py::module &);
void bind_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate(py::module &);
void bind_IGESDefs_MacroDef(py::module &);
void bind_IGESDefs_Protocol(py::module &);
void bind_IGESDefs_ReadWriteModule(py::module &);
void bind_IGESDefs_SpecificModule(py::module &);
void bind_IGESDefs_ToolAssociativityDef(py::module &);
void bind_IGESDefs_ToolAttributeDef(py::module &);
void bind_IGESDefs_ToolAttributeTable(py::module &);
void bind_IGESDefs_ToolGenericData(py::module &);
void bind_IGESDefs_ToolMacroDef(py::module &);
void bind_IGESDefs_ToolTabularData(py::module &);
void bind_IGESDefs_ToolUnitsData(py::module &);
void bind_IGESDefs_UnitsData(py::module &);

PYBIND11_MODULE(IGESDefs, mod) {

py::module::import("OCCT.IGESData");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.IGESBasic");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.IGESGraph");
py::module::import("OCCT.Interface");
py::module::import("OCCT.Message");

bind_IGESDefs_TabularData(mod);
bind_IGESDefs_Array1OfTabularData(mod);
bind_IGESDefs_HArray1OfTabularData(mod);
bind_IGESDefs(mod);
bind_IGESDefs_AssociativityDef(mod);
bind_IGESDefs_AttributeDef(mod);
bind_IGESDefs_AttributeTable(mod);
bind_IGESDefs_GeneralModule(mod);
bind_IGESDefs_GenericData(mod);
bind_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate(mod);
bind_IGESDefs_MacroDef(mod);
bind_IGESDefs_Protocol(mod);
bind_IGESDefs_ReadWriteModule(mod);
bind_IGESDefs_SpecificModule(mod);
bind_IGESDefs_ToolAssociativityDef(mod);
bind_IGESDefs_ToolAttributeDef(mod);
bind_IGESDefs_ToolAttributeTable(mod);
bind_IGESDefs_ToolGenericData(mod);
bind_IGESDefs_ToolMacroDef(mod);
bind_IGESDefs_ToolTabularData(mod);
bind_IGESDefs_ToolUnitsData(mod);
bind_IGESDefs_UnitsData(mod);

}
