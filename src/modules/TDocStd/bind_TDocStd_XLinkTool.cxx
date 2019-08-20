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
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TDF_DataSet.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDocStd_XLinkTool.hxx>

void bind_TDocStd_XLinkTool(py::module &mod){

py::class_<TDocStd_XLinkTool, std::unique_ptr<TDocStd_XLinkTool>> cls_TDocStd_XLinkTool(mod, "TDocStd_XLinkTool", "This tool class is used to copy the content of source label under target label. Only child labels and attributes of source are copied. attributes located out of source scope are not copied by this algorithm. Depending of the called method an external reference is set in the the target document to registred the externallink. Provide services to set, update and perform external references. Warning1: Nothing is provided in this class about the opportunity to copy, set a link or update it. Such decisions must be under application control. Warning2: If the document manages shapes, use after copy TNaming::ChangeShapes(target,M) to make copy of shapes.");

// Constructors
cls_TDocStd_XLinkTool.def(py::init<>());

// Fields

// Methods
// cls_TDocStd_XLinkTool.def_static("operator new_", (void * (*)(size_t)) &TDocStd_XLinkTool::operator new, "None", py::arg("theSize"));
// cls_TDocStd_XLinkTool.def_static("operator delete_", (void (*)(void *)) &TDocStd_XLinkTool::operator delete, "None", py::arg("theAddress"));
// cls_TDocStd_XLinkTool.def_static("operator new[]_", (void * (*)(size_t)) &TDocStd_XLinkTool::operator new[], "None", py::arg("theSize"));
// cls_TDocStd_XLinkTool.def_static("operator delete[]_", (void (*)(void *)) &TDocStd_XLinkTool::operator delete[], "None", py::arg("theAddress"));
// cls_TDocStd_XLinkTool.def_static("operator new_", (void * (*)(size_t, void *)) &TDocStd_XLinkTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDocStd_XLinkTool.def_static("operator delete_", (void (*)(void *, void *)) &TDocStd_XLinkTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TDocStd_XLinkTool.def("CopyWithLink", (void (TDocStd_XLinkTool::*)(const TDF_Label &, const TDF_Label &)) &TDocStd_XLinkTool::CopyWithLink, "Copies the content of the label <fromsource> to the label <intarget>. The link is registred with an XLink attribute by <intarget> label. if the content of <fromsource> is not self-contained, and/or <intarget> has already an XLink attribute, an exception is raised.", py::arg("intarget"), py::arg("fromsource"));
cls_TDocStd_XLinkTool.def("UpdateLink", (void (TDocStd_XLinkTool::*)(const TDF_Label &)) &TDocStd_XLinkTool::UpdateLink, "Update the external reference set at <L>. Example Handle(TDocStd_Document) aDoc; if (!OCAFTest::GetDocument(1,aDoc)) return 1; Handle(TDataStd_Reference) aRef; TDocStd_XLinkTool xlinktool; if (!OCAFTest::Find(aDoc,2),TDataStd_Reference::GetID(),aRef) return 1; xlinktool.UpdateLink(aRef->Label()); Exceptions Standard_DomainError if <L> has no XLink attribute.", py::arg("L"));
cls_TDocStd_XLinkTool.def("Copy", (void (TDocStd_XLinkTool::*)(const TDF_Label &, const TDF_Label &)) &TDocStd_XLinkTool::Copy, "Copy the content of <fromsource> under <intarget>. Noone link is registred. noone check is done. Example Handle(TDocStd_Document) DOC, XDOC; TDF_Label L, XL; TDocStd_XLinkTool xlinktool; xlinktool.Copy(L,XL); Exceptions: Standard_DomainError if the contents of fromsource are not entirely in the scope of this label, in other words, are not self-contained. !!! ==> Warning: If the document manages shapes use the next way: TDocStd_XLinkTool xlinktool; xlinktool.Copy(L,XL); TopTools_DataMapOfShapeShape M; TNaming::ChangeShapes(target,M);", py::arg("intarget"), py::arg("fromsource"));
cls_TDocStd_XLinkTool.def("IsDone", (Standard_Boolean (TDocStd_XLinkTool::*)() const) &TDocStd_XLinkTool::IsDone, "None");
cls_TDocStd_XLinkTool.def("DataSet", (opencascade::handle<TDF_DataSet> (TDocStd_XLinkTool::*)() const) &TDocStd_XLinkTool::DataSet, "None");
cls_TDocStd_XLinkTool.def("RelocationTable", (opencascade::handle<TDF_RelocationTable> (TDocStd_XLinkTool::*)() const) &TDocStd_XLinkTool::RelocationTable, "None");

// Enums

}