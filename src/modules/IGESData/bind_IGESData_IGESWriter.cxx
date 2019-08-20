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
#include <Standard_Handle.hxx>
#include <IGESData_IGESModel.hxx>
#include <IGESData_IGESWriter.hxx>
#include <Interface_FloatWriter.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_Protocol.hxx>
#include <IGESData_GlobalSection.hxx>
#include <IGESData_IGESEntity.hxx>
#include <TCollection_HAsciiString.hxx>
#include <gp_XY.hxx>
#include <gp_XYZ.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <Standard_OStream.hxx>
#include <IGESData_Array1OfDirPart.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <IGESData_ReadStage.hxx>
#include <Interface_LineBuffer.hxx>

void bind_IGESData_IGESWriter(py::module &mod){

py::class_<IGESData_IGESWriter, std::unique_ptr<IGESData_IGESWriter>> cls_IGESData_IGESWriter(mod, "IGESData_IGESWriter", "manages atomic file writing, under control of IGESModel : prepare text to be sent then sends it takes into account distinction between successive Sections");

// Constructors
cls_IGESData_IGESWriter.def(py::init<const opencascade::handle<IGESData_IGESModel> &>(), py::arg("amodel"));
cls_IGESData_IGESWriter.def(py::init<>());
cls_IGESData_IGESWriter.def(py::init<const IGESData_IGESWriter &>(), py::arg("other"));

// Fields

// Methods
// cls_IGESData_IGESWriter.def_static("operator new_", (void * (*)(size_t)) &IGESData_IGESWriter::operator new, "None", py::arg("theSize"));
// cls_IGESData_IGESWriter.def_static("operator delete_", (void (*)(void *)) &IGESData_IGESWriter::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_IGESWriter.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_IGESWriter::operator new[], "None", py::arg("theSize"));
// cls_IGESData_IGESWriter.def_static("operator delete[]_", (void (*)(void *)) &IGESData_IGESWriter::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_IGESWriter.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_IGESWriter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_IGESWriter.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_IGESWriter::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_IGESWriter.def("FloatWriter", (Interface_FloatWriter & (IGESData_IGESWriter::*)()) &IGESData_IGESWriter::FloatWriter, "Returns the embedded FloatWriter, which controls sending Reals Use this method to access FloatWriter in order to consult or change its options (MainFormat, FormatForRange,ZeroSuppress), because it is returned as the address of its field");
cls_IGESData_IGESWriter.def("WriteMode", (Standard_Integer & (IGESData_IGESWriter::*)()) &IGESData_IGESWriter::WriteMode, "Returns the write mode, in order to be read and/or changed Write Mode controls the way final print works 0 (D) : Normal IGES, 10 : FNES");
cls_IGESData_IGESWriter.def("SendStartLine", (void (IGESData_IGESWriter::*)(const Standard_CString)) &IGESData_IGESWriter::SendStartLine, "Sends an additionnal Starting Line : this is the way used to send comments in an IGES File (at beginning of the file). If the line is more than 72 char.s long, it is splited into as many lines as required to send it completely", py::arg("startline"));
cls_IGESData_IGESWriter.def("SendModel", (void (IGESData_IGESWriter::*)(const opencascade::handle<IGESData_Protocol> &)) &IGESData_IGESWriter::SendModel, "Sends the complete IGESModel (Global Section, Entities as Directory Entries & Parameter Lists, etc...) i.e. fills a list of texts. Once filled, it can be sent by method Print", py::arg("protocol"));
cls_IGESData_IGESWriter.def("SectionS", (void (IGESData_IGESWriter::*)()) &IGESData_IGESWriter::SectionS, "declares sending of S section (only a declaration) error if state is not initial");
cls_IGESData_IGESWriter.def("SectionG", (void (IGESData_IGESWriter::*)(const IGESData_GlobalSection &)) &IGESData_IGESWriter::SectionG, "prepares sending of header, from a GlobalSection (stores it) error if SectionS was not called just before takes in account special characters (Separator, EndMark)", py::arg("header"));
cls_IGESData_IGESWriter.def("SectionsDP", (void (IGESData_IGESWriter::*)()) &IGESData_IGESWriter::SectionsDP, "prepares sending of list of entities, as Sections D (directory list) and P (Parameters lists, one per entity) Entities will be then processed, one after the other error if SectionG has not be called just before");
cls_IGESData_IGESWriter.def("SectionT", (void (IGESData_IGESWriter::*)()) &IGESData_IGESWriter::SectionT, "declares sending of T section (only a declaration) error if does not follow Entities sending");
cls_IGESData_IGESWriter.def("DirPart", (void (IGESData_IGESWriter::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_IGESWriter::DirPart, "translates directory part of an Entity into a litteral DirPart Some infos are computed after sending parameters Error if not in sections DP or Stage not 'Dir'", py::arg("anent"));
cls_IGESData_IGESWriter.def("OwnParams", (void (IGESData_IGESWriter::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_IGESWriter::OwnParams, "sends own parameters of the entity, by sending firstly its type, then calling specific method WriteOwnParams Error if not in sections DP or Stage not 'Own'", py::arg("anent"));
cls_IGESData_IGESWriter.def("Associativities", (void (IGESData_IGESWriter::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_IGESWriter::Associativities, "sends associativity list, as complement of parameters list error if not in sections DP or Stage not 'Associativity'", py::arg("anent"));
cls_IGESData_IGESWriter.def("Properties", (void (IGESData_IGESWriter::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_IGESWriter::Properties, "sends property list, as complement of parameters list error if not in sections DP or Stage not 'Property'", py::arg("anent"));
cls_IGESData_IGESWriter.def("EndEntity", (void (IGESData_IGESWriter::*)()) &IGESData_IGESWriter::EndEntity, "declares end of sending an entity (ends param list by ';')");
cls_IGESData_IGESWriter.def("SendVoid", (void (IGESData_IGESWriter::*)()) &IGESData_IGESWriter::SendVoid, "sends a void parameter, that is null text");
cls_IGESData_IGESWriter.def("Send", (void (IGESData_IGESWriter::*)(const Standard_Integer)) &IGESData_IGESWriter::Send, "sends an Integer parameter", py::arg("val"));
cls_IGESData_IGESWriter.def("SendBoolean", (void (IGESData_IGESWriter::*)(const Standard_Boolean)) &IGESData_IGESWriter::SendBoolean, "sends a Boolean parameter as an Integer value 0(False)/1(True)", py::arg("val"));
cls_IGESData_IGESWriter.def("Send", (void (IGESData_IGESWriter::*)(const Standard_Real)) &IGESData_IGESWriter::Send, "sends a Real parameter. Works with FloatWriter", py::arg("val"));
cls_IGESData_IGESWriter.def("Send", (void (IGESData_IGESWriter::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_IGESWriter::Send, "sends a Text parameter under Hollerith form", py::arg("val"));
cls_IGESData_IGESWriter.def("Send", [](IGESData_IGESWriter &self, const opencascade::handle<IGESData_IGESEntity> & a0) -> void { return self.Send(a0); });
cls_IGESData_IGESWriter.def("Send", (void (IGESData_IGESWriter::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Boolean)) &IGESData_IGESWriter::Send, "sends a Reference to an Entity (if its Number is N, its pointer is 2*N-1) If <val> is Null, '0' will be sent If <negative> is True, 'Pointer' is sent as negative", py::arg("val"), py::arg("negative"));
cls_IGESData_IGESWriter.def("SendString", (void (IGESData_IGESWriter::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_IGESWriter::SendString, "sends a parameter under its exact form given as a string", py::arg("val"));
cls_IGESData_IGESWriter.def("Send", (void (IGESData_IGESWriter::*)(const gp_XY &)) &IGESData_IGESWriter::Send, "Sends a XY, interpreted as a couple of 2 Reals (X & Y)", py::arg("val"));
cls_IGESData_IGESWriter.def("Send", (void (IGESData_IGESWriter::*)(const gp_XYZ &)) &IGESData_IGESWriter::Send, "Sends a XYZ, interpreted as a couple of 2 Reals (X , Y & Z)", py::arg("val"));
cls_IGESData_IGESWriter.def("SectionStrings", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IGESData_IGESWriter::*)(const Standard_Integer) const) &IGESData_IGESWriter::SectionStrings, "Returns the list of strings for a section given its rank 1 : Start (if not empty) 2 : Global 3 or 4 : Parameters RQ: no string list for Directory section An empty section gives a null handle", py::arg("numsec"));
cls_IGESData_IGESWriter.def("Print", (Standard_Boolean (IGESData_IGESWriter::*)(Standard_OStream &) const) &IGESData_IGESWriter::Print, "Writes result on an output defined as an OStream resolves stored infos at this time; in particular, numbers of lines used to adress P-section from D-section and final totals Takes WriteMode into account", py::arg("S"));

// Enums

}