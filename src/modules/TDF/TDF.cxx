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

void bind_TDF_LabelNodePtr(py::module &);
void bind_TDF_AttributeIndexedMap(py::module &);
void bind_TDF_Label(py::module &);
void bind_TDF_Attribute(py::module &);
void bind_TDF_HAllocator(py::module &);
void bind_TDF_LabelNode(py::module &);
void bind_TDF_TagSource(py::module &);
void bind_TDF_Data(py::module &);
void bind_TDF_LabelList(py::module &);
void bind_TDF_ListIteratorOfLabelList(py::module &);
void bind_TDF_LabelSequence(py::module &);
void bind_TDF_AttributeList(py::module &);
void bind_TDF_ListIteratorOfAttributeList(py::module &);
void bind_TDF_Reference(py::module &);
void bind_TDF_LabelMapHasher(py::module &);
void bind_TDF_LabelMap(py::module &);
void bind_TDF_MapIteratorOfLabelMap(py::module &);
void bind_TDF_IDList(py::module &);
void bind_TDF_ListIteratorOfIDList(py::module &);
void bind_TDF_AttributeDelta(py::module &);
void bind_TDF_DeltaOnModification(py::module &);
void bind_TDF(py::module &);
void bind_TDF_AttributeArray1(py::module &);
void bind_TDF_AttributeDataMap(py::module &);
void bind_TDF_DataMapIteratorOfAttributeDataMap(py::module &);
void bind_TDF_AttributeDeltaList(py::module &);
void bind_TDF_ListIteratorOfAttributeDeltaList(py::module &);
void bind_TDF_AttributeDoubleMap(py::module &);
void bind_TDF_DoubleMapIteratorOfAttributeDoubleMap(py::module &);
void bind_TDF_AttributeIterator(py::module &);
void bind_TDF_AttributeMap(py::module &);
void bind_TDF_MapIteratorOfAttributeMap(py::module &);
void bind_TDF_AttributeSequence(py::module &);
void bind_TDF_ChildIterator(py::module &);
void bind_TDF_ChildIDIterator(py::module &);
void bind_TDF_ClosureMode(py::module &);
void bind_TDF_ClosureTool(py::module &);
void bind_TDF_ComparisonTool(py::module &);
void bind_TDF_IDMap(py::module &);
void bind_TDF_MapIteratorOfIDMap(py::module &);
void bind_TDF_IDFilter(py::module &);
void bind_TDF_CopyLabel(py::module &);
void bind_TDF_LabelDataMap(py::module &);
void bind_TDF_DataMapIteratorOfLabelDataMap(py::module &);
void bind_TDF_CopyTool(py::module &);
void bind_TDF_LabelIntegerMap(py::module &);
void bind_TDF_DataMapIteratorOfLabelIntegerMap(py::module &);
void bind_TDF_DataSet(py::module &);
void bind_TDF_DefaultDeltaOnModification(py::module &);
void bind_TDF_DeltaOnRemoval(py::module &);
void bind_TDF_DefaultDeltaOnRemoval(py::module &);
void bind_TDF_Delta(py::module &);
void bind_TDF_DeltaList(py::module &);
void bind_TDF_ListIteratorOfDeltaList(py::module &);
void bind_TDF_DeltaOnAddition(py::module &);
void bind_TDF_DeltaOnForget(py::module &);
void bind_TDF_DeltaOnResume(py::module &);
void bind_TDF_GUIDProgIDMap(py::module &);
void bind_TDF_DoubleMapIteratorOfGUIDProgIDMap(py::module &);
void bind_TDF_LabelDoubleMap(py::module &);
void bind_TDF_DoubleMapIteratorOfLabelDoubleMap(py::module &);
void bind_TDF_HAttributeArray1(py::module &);
void bind_TDF_LabelIndexedMap(py::module &);
void bind_TDF_RelocationTable(py::module &);
void bind_TDF_Tool(py::module &);
void bind_TDF_Transaction(py::module &);

PYBIND11_MODULE(TDF, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TCollection");

bind_TDF_LabelNodePtr(mod);
bind_TDF_AttributeIndexedMap(mod);
bind_TDF_Label(mod);
bind_TDF_Attribute(mod);
bind_TDF_HAllocator(mod);
bind_TDF_LabelNode(mod);
bind_TDF_TagSource(mod);
bind_TDF_Data(mod);
bind_TDF_LabelList(mod);
bind_TDF_ListIteratorOfLabelList(mod);
bind_TDF_LabelSequence(mod);
bind_TDF_AttributeList(mod);
bind_TDF_ListIteratorOfAttributeList(mod);
bind_TDF_Reference(mod);
bind_TDF_LabelMapHasher(mod);
bind_TDF_LabelMap(mod);
bind_TDF_MapIteratorOfLabelMap(mod);
bind_TDF_IDList(mod);
bind_TDF_ListIteratorOfIDList(mod);
bind_TDF_AttributeDelta(mod);
bind_TDF_DeltaOnModification(mod);
bind_TDF(mod);
bind_TDF_AttributeArray1(mod);
bind_TDF_AttributeDataMap(mod);
bind_TDF_DataMapIteratorOfAttributeDataMap(mod);
bind_TDF_AttributeDeltaList(mod);
bind_TDF_ListIteratorOfAttributeDeltaList(mod);
bind_TDF_AttributeDoubleMap(mod);
bind_TDF_DoubleMapIteratorOfAttributeDoubleMap(mod);
bind_TDF_AttributeIterator(mod);
bind_TDF_AttributeMap(mod);
bind_TDF_MapIteratorOfAttributeMap(mod);
bind_TDF_AttributeSequence(mod);
bind_TDF_ChildIterator(mod);
bind_TDF_ChildIDIterator(mod);
bind_TDF_ClosureMode(mod);
bind_TDF_ClosureTool(mod);
bind_TDF_ComparisonTool(mod);
bind_TDF_IDMap(mod);
bind_TDF_MapIteratorOfIDMap(mod);
bind_TDF_IDFilter(mod);
bind_TDF_CopyLabel(mod);
bind_TDF_LabelDataMap(mod);
bind_TDF_DataMapIteratorOfLabelDataMap(mod);
bind_TDF_CopyTool(mod);
bind_TDF_LabelIntegerMap(mod);
bind_TDF_DataMapIteratorOfLabelIntegerMap(mod);
bind_TDF_DataSet(mod);
bind_TDF_DefaultDeltaOnModification(mod);
bind_TDF_DeltaOnRemoval(mod);
bind_TDF_DefaultDeltaOnRemoval(mod);
bind_TDF_Delta(mod);
bind_TDF_DeltaList(mod);
bind_TDF_ListIteratorOfDeltaList(mod);
bind_TDF_DeltaOnAddition(mod);
bind_TDF_DeltaOnForget(mod);
bind_TDF_DeltaOnResume(mod);
bind_TDF_GUIDProgIDMap(mod);
bind_TDF_DoubleMapIteratorOfGUIDProgIDMap(mod);
bind_TDF_LabelDoubleMap(mod);
bind_TDF_DoubleMapIteratorOfLabelDoubleMap(mod);
bind_TDF_HAttributeArray1(mod);
bind_TDF_LabelIndexedMap(mod);
bind_TDF_RelocationTable(mod);
bind_TDF_Tool(mod);
bind_TDF_Transaction(mod);

}
