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

void bind_Interface_DataState(py::module &);
void bind_Interface_CheckStatus(py::module &);
void bind_Interface_ParamType(py::module &);
void bind_Interface_Array1OfHAsciiString(py::module &);
void bind_Interface_HArray1OfHAsciiString(py::module &);
void bind_Interface_DataMapOfTransientInteger(py::module &);
void bind_Interface_DataMapIteratorOfDataMapOfTransientInteger(py::module &);
void bind_Interface_Protocol(py::module &);
void bind_Interface_BitMap(py::module &);
void bind_Interface_InterfaceModel(py::module &);
void bind_Interface_Graph(py::module &);
void bind_Interface_EntityIterator(py::module &);
void bind_Interface_GraphContent(py::module &);
void bind_Interface_IntList(py::module &);
void bind_Interface_Check(py::module &);
void bind_Interface_SequenceOfCheck(py::module &);
void bind_Interface_HSequenceOfCheck(py::module &);
void bind_Interface_CheckIterator(py::module &);
void bind_Interface_SignType(py::module &);
void bind_Interface_EntityList(py::module &);
void bind_Interface_GeneralModule(py::module &);
void bind_Interface_ReaderModule(py::module &);
void bind_Interface_GeneralLib(py::module &);
void bind_Interface_MSG(py::module &);
void bind_Interface_FileReaderData(py::module &);
void bind_Interface_ReaderLib(py::module &);
void bind_Interface_FileReaderTool(py::module &);
void bind_Interface_LineBuffer(py::module &);
void bind_Interface_FloatWriter(py::module &);
void bind_Interface_FileParameter(py::module &);
void bind_Interface_Array1OfFileParameter(py::module &);
void bind_Interface_GTool(py::module &);
void bind_Interface_Category(py::module &);
void bind_Interface_InterfaceError(py::module &);
void bind_Interface_CheckFailure(py::module &);
void bind_Interface_ShareTool(py::module &);
void bind_Interface_CheckTool(py::module &);
void bind_Interface_CopyControl(py::module &);
void bind_Interface_CopyMap(py::module &);
void bind_Interface_CopyTool(py::module &);
void bind_Interface_EntityCluster(py::module &);
void bind_Interface_GlobalNodeOfGeneralLib(py::module &);
void bind_Interface_GlobalNodeOfReaderLib(py::module &);
void bind_Interface_HGraph(py::module &);
void bind_Interface_MapAsciiStringHasher(py::module &);
void bind_Interface_IndexedMapOfAsciiString(py::module &);
void bind_Interface_InterfaceMismatch(py::module &);
void bind_Interface_IntVal(py::module &);
void bind_Interface_NodeOfGeneralLib(py::module &);
void bind_Interface_NodeOfReaderLib(py::module &);
void bind_Interface_VectorOfFileParameter(py::module &);
void bind_Interface_ParamList(py::module &);
void bind_Interface_ParamSet(py::module &);
void bind_Interface_ReportEntity(py::module &);
void bind_Interface_ShareFlags(py::module &);
void bind_Interface_SignLabel(py::module &);
void bind_Interface_STAT(py::module &);
void bind_Interface_StaticSatisfies(py::module &);
void bind_Interface_TypedValue(py::module &);
void bind_Interface_Static(py::module &);
void bind_Interface_UndefinedContent(py::module &);
void bind_Interface_ValueInterpret(py::module &);
void bind_Interface_ValueSatisfies(py::module &);

PYBIND11_MODULE(Interface, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Message");
py::module::import("OCCT.MoniTool");

bind_Interface_DataState(mod);
bind_Interface_CheckStatus(mod);
bind_Interface_ParamType(mod);
bind_Interface_Array1OfHAsciiString(mod);
bind_Interface_HArray1OfHAsciiString(mod);
bind_Interface_DataMapOfTransientInteger(mod);
bind_Interface_DataMapIteratorOfDataMapOfTransientInteger(mod);
bind_Interface_Protocol(mod);
bind_Interface_BitMap(mod);
bind_Interface_InterfaceModel(mod);
bind_Interface_Graph(mod);
bind_Interface_EntityIterator(mod);
bind_Interface_GraphContent(mod);
bind_Interface_IntList(mod);
bind_Interface_Check(mod);
bind_Interface_SequenceOfCheck(mod);
bind_Interface_HSequenceOfCheck(mod);
bind_Interface_CheckIterator(mod);
bind_Interface_SignType(mod);
bind_Interface_EntityList(mod);
bind_Interface_GeneralModule(mod);
bind_Interface_ReaderModule(mod);
bind_Interface_GeneralLib(mod);
bind_Interface_MSG(mod);
bind_Interface_FileReaderData(mod);
bind_Interface_ReaderLib(mod);
bind_Interface_FileReaderTool(mod);
bind_Interface_LineBuffer(mod);
bind_Interface_FloatWriter(mod);
bind_Interface_FileParameter(mod);
bind_Interface_Array1OfFileParameter(mod);
bind_Interface_GTool(mod);
bind_Interface_Category(mod);
bind_Interface_InterfaceError(mod);
bind_Interface_CheckFailure(mod);
bind_Interface_ShareTool(mod);
bind_Interface_CheckTool(mod);
bind_Interface_CopyControl(mod);
bind_Interface_CopyMap(mod);
bind_Interface_CopyTool(mod);
bind_Interface_EntityCluster(mod);
bind_Interface_GlobalNodeOfGeneralLib(mod);
bind_Interface_GlobalNodeOfReaderLib(mod);
bind_Interface_HGraph(mod);
bind_Interface_MapAsciiStringHasher(mod);
bind_Interface_IndexedMapOfAsciiString(mod);
bind_Interface_InterfaceMismatch(mod);
bind_Interface_IntVal(mod);
bind_Interface_NodeOfGeneralLib(mod);
bind_Interface_NodeOfReaderLib(mod);
bind_Interface_VectorOfFileParameter(mod);
bind_Interface_ParamList(mod);
bind_Interface_ParamSet(mod);
bind_Interface_ReportEntity(mod);
bind_Interface_ShareFlags(mod);
bind_Interface_SignLabel(mod);
bind_Interface_STAT(mod);
bind_Interface_StaticSatisfies(mod);
bind_Interface_TypedValue(mod);
bind_Interface_Static(mod);
bind_Interface_UndefinedContent(mod);
bind_Interface_ValueInterpret(mod);
bind_Interface_ValueSatisfies(mod);

}
