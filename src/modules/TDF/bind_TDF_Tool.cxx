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
#include <Standard_TypeDef.hxx>
#include <TDF_Label.hxx>
#include <TDF_IDFilter.hxx>
#include <TDF_AttributeMap.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Data.hxx>
#include <TDF_LabelList.hxx>
#include <TDF_LabelIntegerMap.hxx>
#include <Standard_OStream.hxx>
#include <TDF_Tool.hxx>

void bind_TDF_Tool(py::module &mod){

py::class_<TDF_Tool, std::unique_ptr<TDF_Tool, Deleter<TDF_Tool>>> cls_TDF_Tool(mod, "TDF_Tool", "This class provides general services for a data framework.");

// Constructors

// Fields

// Methods
// cls_TDF_Tool.def_static("operator new_", (void * (*)(size_t)) &TDF_Tool::operator new, "None", py::arg("theSize"));
// cls_TDF_Tool.def_static("operator delete_", (void (*)(void *)) &TDF_Tool::operator delete, "None", py::arg("theAddress"));
// cls_TDF_Tool.def_static("operator new[]_", (void * (*)(size_t)) &TDF_Tool::operator new[], "None", py::arg("theSize"));
// cls_TDF_Tool.def_static("operator delete[]_", (void (*)(void *)) &TDF_Tool::operator delete[], "None", py::arg("theAddress"));
// cls_TDF_Tool.def_static("operator new_", (void * (*)(size_t, void *)) &TDF_Tool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDF_Tool.def_static("operator delete_", (void (*)(void *, void *)) &TDF_Tool::operator delete, "None", py::arg(""), py::arg(""));
cls_TDF_Tool.def_static("NbLabels_", (Standard_Integer (*)(const TDF_Label &)) &TDF_Tool::NbLabels, "Returns the number of labels of the tree, including <aLabel>. aLabel is also included in this figure. This information is useful in setting the size of an array.", py::arg("aLabel"));
cls_TDF_Tool.def_static("NbAttributes_", (Standard_Integer (*)(const TDF_Label &)) &TDF_Tool::NbAttributes, "Returns the total number of attributes attached to the labels dependent on the label aLabel. The attributes of aLabel are also included in this figure. This information is useful in setting the size of an array.", py::arg("aLabel"));
cls_TDF_Tool.def_static("NbAttributes_", (Standard_Integer (*)(const TDF_Label &, const TDF_IDFilter &)) &TDF_Tool::NbAttributes, "Returns the number of attributes of the tree, selected by a<Filter>, including those of <aLabel>.", py::arg("aLabel"), py::arg("aFilter"));
cls_TDF_Tool.def_static("IsSelfContained_", (Standard_Boolean (*)(const TDF_Label &)) &TDF_Tool::IsSelfContained, "Returns true if <aLabel> and its descendants reference only attributes or labels attached to themselves.", py::arg("aLabel"));
cls_TDF_Tool.def_static("IsSelfContained_", (Standard_Boolean (*)(const TDF_Label &, const TDF_IDFilter &)) &TDF_Tool::IsSelfContained, "Returns true if <aLabel> and its descendants reference only attributes or labels attached to themselves and kept by <aFilter>.", py::arg("aLabel"), py::arg("aFilter"));
cls_TDF_Tool.def_static("OutReferers_", (void (*)(const TDF_Label &, TDF_AttributeMap &)) &TDF_Tool::OutReferers, "Returns in <theAtts> the attributes having out references.", py::arg("theLabel"), py::arg("theAtts"));
cls_TDF_Tool.def_static("OutReferers_", (void (*)(const TDF_Label &, const TDF_IDFilter &, const TDF_IDFilter &, TDF_AttributeMap &)) &TDF_Tool::OutReferers, "Returns in <atts> the attributes having out references and kept by <aFilterForReferers>. It considers only the references kept by <aFilterForReferences>. Caution: <atts> is not cleared before use!", py::arg("aLabel"), py::arg("aFilterForReferers"), py::arg("aFilterForReferences"), py::arg("atts"));
cls_TDF_Tool.def_static("OutReferences_", (void (*)(const TDF_Label &, TDF_AttributeMap &)) &TDF_Tool::OutReferences, "Returns in <atts> the referenced attributes. Caution: <atts> is not cleared before use!", py::arg("aLabel"), py::arg("atts"));
cls_TDF_Tool.def_static("OutReferences_", (void (*)(const TDF_Label &, const TDF_IDFilter &, const TDF_IDFilter &, TDF_AttributeMap &)) &TDF_Tool::OutReferences, "Returns in <atts> the referenced attributes and kept by <aFilterForReferences>. It considers only the referers kept by <aFilterForReferers>. Caution: <atts> is not cleared before use!", py::arg("aLabel"), py::arg("aFilterForReferers"), py::arg("aFilterForReferences"), py::arg("atts"));
cls_TDF_Tool.def_static("RelocateLabel_", [](const TDF_Label & a0, const TDF_Label & a1, const TDF_Label & a2, TDF_Label & a3) -> void { return TDF_Tool::RelocateLabel(a0, a1, a2, a3); });
cls_TDF_Tool.def_static("RelocateLabel_", (void (*)(const TDF_Label &, const TDF_Label &, const TDF_Label &, TDF_Label &, const Standard_Boolean)) &TDF_Tool::RelocateLabel, "Returns the label having the same sub-entry as <aLabel> but located as descendant as <toRoot> instead of <fromRoot>.", py::arg("aSourceLabel"), py::arg("fromRoot"), py::arg("toRoot"), py::arg("aTargetLabel"), py::arg("create"));
cls_TDF_Tool.def_static("Entry_", (void (*)(const TDF_Label &, TCollection_AsciiString &)) &TDF_Tool::Entry, "Returns the entry for the label aLabel in the form of the ASCII character string anEntry containing the tag list for aLabel.", py::arg("aLabel"), py::arg("anEntry"));
cls_TDF_Tool.def_static("TagList_", (void (*)(const TDF_Label &, TColStd_ListOfInteger &)) &TDF_Tool::TagList, "Returns the entry of <aLabel> as list of integers in <aTagList>.", py::arg("aLabel"), py::arg("aTagList"));
cls_TDF_Tool.def_static("TagList_", (void (*)(const TCollection_AsciiString &, TColStd_ListOfInteger &)) &TDF_Tool::TagList, "Returns the entry expressed by <anEntry> as list of integers in <aTagList>.", py::arg("anEntry"), py::arg("aTagList"));
cls_TDF_Tool.def_static("Label_", [](const opencascade::handle<TDF_Data> & a0, const TCollection_AsciiString & a1, TDF_Label & a2) -> void { return TDF_Tool::Label(a0, a1, a2); });
cls_TDF_Tool.def_static("Label_", (void (*)(const opencascade::handle<TDF_Data> &, const TCollection_AsciiString &, TDF_Label &, const Standard_Boolean)) &TDF_Tool::Label, "Returns the label expressed by <anEntry>; creates the label if it does not exist and if <create> is true.", py::arg("aDF"), py::arg("anEntry"), py::arg("aLabel"), py::arg("create"));
cls_TDF_Tool.def_static("Label_", [](const opencascade::handle<TDF_Data> & a0, const Standard_CString a1, TDF_Label & a2) -> void { return TDF_Tool::Label(a0, a1, a2); });
cls_TDF_Tool.def_static("Label_", (void (*)(const opencascade::handle<TDF_Data> &, const Standard_CString, TDF_Label &, const Standard_Boolean)) &TDF_Tool::Label, "Returns the label expressed by <anEntry>; creates the label if it does not exist and if <create> is true.", py::arg("aDF"), py::arg("anEntry"), py::arg("aLabel"), py::arg("create"));
cls_TDF_Tool.def_static("Label_", [](const opencascade::handle<TDF_Data> & a0, const TColStd_ListOfInteger & a1, TDF_Label & a2) -> void { return TDF_Tool::Label(a0, a1, a2); });
cls_TDF_Tool.def_static("Label_", (void (*)(const opencascade::handle<TDF_Data> &, const TColStd_ListOfInteger &, TDF_Label &, const Standard_Boolean)) &TDF_Tool::Label, "Returns the label expressed by <anEntry>; creates the label if it does not exist and if <create> is true.", py::arg("aDF"), py::arg("aTagList"), py::arg("aLabel"), py::arg("create"));
cls_TDF_Tool.def_static("CountLabels_", (void (*)(TDF_LabelList &, TDF_LabelIntegerMap &)) &TDF_Tool::CountLabels, "Adds the labels of <aLabelList> to <aLabelMap> if they are unbound, or increases their reference counters. At the end of the process, <aLabelList> contains only the ADDED labels.", py::arg("aLabelList"), py::arg("aLabelMap"));
cls_TDF_Tool.def_static("DeductLabels_", (void (*)(TDF_LabelList &, TDF_LabelIntegerMap &)) &TDF_Tool::DeductLabels, "Decreases the reference counters of the labels of <aLabelList> to <aLabelMap>, and removes labels with null counter. At the end of the process, <aLabelList> contains only the SUPPRESSED labels.", py::arg("aLabelList"), py::arg("aLabelMap"));
cls_TDF_Tool.def_static("DeepDump_", (void (*)(Standard_OStream &, const opencascade::handle<TDF_Data> &)) &TDF_Tool::DeepDump, "Dumps <aDF> and its labels and their attributes.", py::arg("anOS"), py::arg("aDF"));
cls_TDF_Tool.def_static("ExtendedDeepDump_", (void (*)(Standard_OStream &, const opencascade::handle<TDF_Data> &, const TDF_IDFilter &)) &TDF_Tool::ExtendedDeepDump, "Dumps <aDF> and its labels and their attributes, if their IDs are kept by <aFilter>. Dumps also the attributes content.", py::arg("anOS"), py::arg("aDF"), py::arg("aFilter"));
cls_TDF_Tool.def_static("DeepDump_", (void (*)(Standard_OStream &, const TDF_Label &)) &TDF_Tool::DeepDump, "Dumps <aLabel>, its chilren and their attributes.", py::arg("anOS"), py::arg("aLabel"));
cls_TDF_Tool.def_static("ExtendedDeepDump_", (void (*)(Standard_OStream &, const TDF_Label &, const TDF_IDFilter &)) &TDF_Tool::ExtendedDeepDump, "Dumps <aLabel>, its chilren and their attributes, if their IDs are kept by <aFilter>. Dumps also the attributes content.", py::arg("anOS"), py::arg("aLabel"), py::arg("aFilter"));

// Enums

}