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

void bind_StepData_Logical(py::module &);
void bind_StepData_FileRecognizer(py::module &);
void bind_StepData_Protocol(py::module &);
void bind_StepData_GeneralModule(py::module &);
void bind_StepData_ReadWriteModule(py::module &);
void bind_StepData_StepReaderData(py::module &);
void bind_StepData_SelectType(py::module &);
void bind_StepData_SelectMember(py::module &);
void bind_StepData_SelectReal(py::module &);
void bind_StepData_SelectInt(py::module &);
void bind_StepData(py::module &);
void bind_StepData_Field(py::module &);
void bind_StepData_Array1OfField(py::module &);
void bind_StepData_DefaultGeneral(py::module &);
void bind_StepData_DescrGeneral(py::module &);
void bind_StepData_Described(py::module &);
void bind_StepData_FileProtocol(py::module &);
void bind_StepData_DescrProtocol(py::module &);
void bind_StepData_DescrReadWrite(py::module &);
void bind_StepData_EDescr(py::module &);
void bind_StepData_ECDescr(py::module &);
void bind_StepData_EnumTool(py::module &);
void bind_StepData_ESDescr(py::module &);
void bind_StepData_FieldList(py::module &);
void bind_StepData_FieldList1(py::module &);
void bind_StepData_HArray1OfField(py::module &);
void bind_StepData_FieldListD(py::module &);
void bind_StepData_FieldListN(py::module &);
void bind_StepData_FreeFormEntity(py::module &);
void bind_StepData_GlobalNodeOfWriterLib(py::module &);
void bind_StepData_HeaderTool(py::module &);
void bind_StepData_NodeOfWriterLib(py::module &);
void bind_StepData_PDescr(py::module &);
void bind_StepData_Plex(py::module &);
void bind_StepData_SelectNamed(py::module &);
void bind_StepData_SelectArrReal(py::module &);
void bind_StepData_Simple(py::module &);
void bind_StepData_WriterLib(py::module &);
void bind_StepData_StepWriter(py::module &);
void bind_StepData_StepDumper(py::module &);
void bind_StepData_StepModel(py::module &);
void bind_StepData_StepReaderTool(py::module &);
void bind_StepData_UndefinedEntity(py::module &);

PYBIND11_MODULE(StepData, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.Interface");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Message");

bind_StepData_Logical(mod);
bind_StepData_FileRecognizer(mod);
bind_StepData_Protocol(mod);
bind_StepData_GeneralModule(mod);
bind_StepData_ReadWriteModule(mod);
bind_StepData_StepReaderData(mod);
bind_StepData_SelectType(mod);
bind_StepData_SelectMember(mod);
bind_StepData_SelectReal(mod);
bind_StepData_SelectInt(mod);
bind_StepData(mod);
bind_StepData_Field(mod);
bind_StepData_Array1OfField(mod);
bind_StepData_DefaultGeneral(mod);
bind_StepData_DescrGeneral(mod);
bind_StepData_Described(mod);
bind_StepData_FileProtocol(mod);
bind_StepData_DescrProtocol(mod);
bind_StepData_DescrReadWrite(mod);
bind_StepData_EDescr(mod);
bind_StepData_ECDescr(mod);
bind_StepData_EnumTool(mod);
bind_StepData_ESDescr(mod);
bind_StepData_FieldList(mod);
bind_StepData_FieldList1(mod);
bind_StepData_HArray1OfField(mod);
bind_StepData_FieldListD(mod);
bind_StepData_FieldListN(mod);
bind_StepData_FreeFormEntity(mod);
bind_StepData_GlobalNodeOfWriterLib(mod);
bind_StepData_HeaderTool(mod);
bind_StepData_NodeOfWriterLib(mod);
bind_StepData_PDescr(mod);
bind_StepData_Plex(mod);
bind_StepData_SelectNamed(mod);
bind_StepData_SelectArrReal(mod);
bind_StepData_Simple(mod);
bind_StepData_WriterLib(mod);
bind_StepData_StepWriter(mod);
bind_StepData_StepDumper(mod);
bind_StepData_StepModel(mod);
bind_StepData_StepReaderTool(mod);
bind_StepData_UndefinedEntity(mod);

}
