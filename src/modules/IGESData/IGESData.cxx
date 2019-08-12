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

void bind_IGESData_DefType(py::module &);
void bind_IGESData_DefList(py::module &);
void bind_IGESData_ReadStage(py::module &);
void bind_IGESData_Status(py::module &);
void bind_IGESData_DefSwitch(py::module &);
void bind_IGESData_IGESEntity(py::module &);
void bind_IGESData_Array1OfIGESEntity(py::module &);
void bind_IGESData_HArray1OfIGESEntity(py::module &);
void bind_IGESData_GeneralModule(py::module &);
void bind_IGESData_Protocol(py::module &);
void bind_IGESData_ReadWriteModule(py::module &);
void bind_IGESData_SpecificModule(py::module &);
void bind_IGESData_LineFontEntity(py::module &);
void bind_IGESData_NameEntity(py::module &);
void bind_IGESData_SingleParentEntity(py::module &);
void bind_IGESData_SpecificLib(py::module &);
void bind_IGESData_BasicEditor(py::module &);
void bind_IGESData(py::module &);
void bind_IGESData_DirPart(py::module &);
void bind_IGESData_Array1OfDirPart(py::module &);
void bind_IGESData_ColorEntity(py::module &);
void bind_IGESData_DefaultGeneral(py::module &);
void bind_IGESData_DefaultSpecific(py::module &);
void bind_IGESData_DirChecker(py::module &);
void bind_IGESData_FileProtocol(py::module &);
void bind_IGESData_FileRecognizer(py::module &);
void bind_IGESData_UndefinedEntity(py::module &);
void bind_IGESData_FreeFormatEntity(py::module &);
void bind_IGESData_GlobalNodeOfSpecificLib(py::module &);
void bind_IGESData_GlobalNodeOfWriterLib(py::module &);
void bind_IGESData_GlobalSection(py::module &);
void bind_IGESData_IGESDumper(py::module &);
void bind_IGESData_IGESModel(py::module &);
void bind_IGESData_IGESType(py::module &);
void bind_IGESData_IGESReaderData(py::module &);
void bind_IGESData_IGESReaderTool(py::module &);
void bind_IGESData_IGESWriter(py::module &);
void bind_IGESData_LabelDisplayEntity(py::module &);
void bind_IGESData_LevelListEntity(py::module &);
void bind_IGESData_NodeOfSpecificLib(py::module &);
void bind_IGESData_NodeOfWriterLib(py::module &);
void bind_IGESData_ParamCursor(py::module &);
void bind_IGESData_ParamReader(py::module &);
void bind_IGESData_ToolLocation(py::module &);
void bind_IGESData_TransfEntity(py::module &);
void bind_IGESData_ViewKindEntity(py::module &);
void bind_IGESData_WriterLib(py::module &);

PYBIND11_MODULE(IGESData, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.Interface");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Message");
py::module::import("OCCT.TColStd");

bind_IGESData_DefType(mod);
bind_IGESData_DefList(mod);
bind_IGESData_ReadStage(mod);
bind_IGESData_Status(mod);
bind_IGESData_DefSwitch(mod);
bind_IGESData_IGESEntity(mod);
bind_IGESData_Array1OfIGESEntity(mod);
bind_IGESData_HArray1OfIGESEntity(mod);
bind_IGESData_GeneralModule(mod);
bind_IGESData_Protocol(mod);
bind_IGESData_ReadWriteModule(mod);
bind_IGESData_SpecificModule(mod);
bind_IGESData_LineFontEntity(mod);
bind_IGESData_NameEntity(mod);
bind_IGESData_SingleParentEntity(mod);
bind_IGESData_SpecificLib(mod);
bind_IGESData_BasicEditor(mod);
bind_IGESData(mod);
bind_IGESData_DirPart(mod);
bind_IGESData_Array1OfDirPart(mod);
bind_IGESData_ColorEntity(mod);
bind_IGESData_DefaultGeneral(mod);
bind_IGESData_DefaultSpecific(mod);
bind_IGESData_DirChecker(mod);
bind_IGESData_FileProtocol(mod);
bind_IGESData_FileRecognizer(mod);
bind_IGESData_UndefinedEntity(mod);
bind_IGESData_FreeFormatEntity(mod);
bind_IGESData_GlobalNodeOfSpecificLib(mod);
bind_IGESData_GlobalNodeOfWriterLib(mod);
bind_IGESData_GlobalSection(mod);
bind_IGESData_IGESDumper(mod);
bind_IGESData_IGESModel(mod);
bind_IGESData_IGESType(mod);
bind_IGESData_IGESReaderData(mod);
bind_IGESData_IGESReaderTool(mod);
bind_IGESData_IGESWriter(mod);
bind_IGESData_LabelDisplayEntity(mod);
bind_IGESData_LevelListEntity(mod);
bind_IGESData_NodeOfSpecificLib(mod);
bind_IGESData_NodeOfWriterLib(mod);
bind_IGESData_ParamCursor(mod);
bind_IGESData_ParamReader(mod);
bind_IGESData_ToolLocation(mod);
bind_IGESData_TransfEntity(mod);
bind_IGESData_ViewKindEntity(mod);
bind_IGESData_WriterLib(mod);

}
