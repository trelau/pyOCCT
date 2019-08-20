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
#include <StepData_StepModel.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_FloatWriter.hxx>
#include <StepData_Protocol.hxx>
#include <StepData_WriterLib.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TCollection_AsciiString.hxx>
#include <StepData_Field.hxx>
#include <StepData_PDescr.hxx>
#include <StepData_SelectMember.hxx>
#include <StepData_FieldList.hxx>
#include <StepData_ESDescr.hxx>
#include <Standard_Transient.hxx>
#include <StepData_Logical.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Interface_CheckIterator.hxx>
#include <Standard_OStream.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <Interface_LineBuffer.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <StepData_StepWriter.hxx>

void bind_StepData_StepWriter(py::module &mod){

py::class_<StepData_StepWriter, std::unique_ptr<StepData_StepWriter>> cls_StepData_StepWriter(mod, "StepData_StepWriter", "manages atomic file writing, under control of StepModel (for general organisation of file) and each class of Transient (for its own parameters) : prepares text to be written then writes it A stream cannot be used because Step limits line length at 72 In more, a specific object offers more appropriate functions");

// Constructors
cls_StepData_StepWriter.def(py::init<const opencascade::handle<StepData_StepModel> &>(), py::arg("amodel"));

// Fields

// Methods
// cls_StepData_StepWriter.def_static("operator new_", (void * (*)(size_t)) &StepData_StepWriter::operator new, "None", py::arg("theSize"));
// cls_StepData_StepWriter.def_static("operator delete_", (void (*)(void *)) &StepData_StepWriter::operator delete, "None", py::arg("theAddress"));
// cls_StepData_StepWriter.def_static("operator new[]_", (void * (*)(size_t)) &StepData_StepWriter::operator new[], "None", py::arg("theSize"));
// cls_StepData_StepWriter.def_static("operator delete[]_", (void (*)(void *)) &StepData_StepWriter::operator delete[], "None", py::arg("theAddress"));
// cls_StepData_StepWriter.def_static("operator new_", (void * (*)(size_t, void *)) &StepData_StepWriter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepData_StepWriter.def_static("operator delete_", (void (*)(void *, void *)) &StepData_StepWriter::operator delete, "None", py::arg(""), py::arg(""));
cls_StepData_StepWriter.def("LabelMode", (Standard_Integer & (StepData_StepWriter::*)()) &StepData_StepWriter::LabelMode, "ModeLabel controls how to display entity ids : 0 (D) gives entity number in the model 1 gives the already recorded label (else, its number) Warning : conflicts are not controlled");
cls_StepData_StepWriter.def("TypeMode", (Standard_Integer & (StepData_StepWriter::*)()) &StepData_StepWriter::TypeMode, "TypeMode controls the type form to use : 0 (D) for normal long form 1 for short form (if a type name has no short form, normal long form is then used)");
cls_StepData_StepWriter.def("FloatWriter", (Interface_FloatWriter & (StepData_StepWriter::*)()) &StepData_StepWriter::FloatWriter, "Returns the embedded FloatWriter, which controls sending Reals Use this method to access FloatWriter in order to consult or change its options (MainFormat, FormatForRange,ZeroSuppress), because it is returned as the address of its field");
cls_StepData_StepWriter.def("SetScope", (void (StepData_StepWriter::*)(const Standard_Integer, const Standard_Integer)) &StepData_StepWriter::SetScope, "Declares the Entity Number <numscope> to correspond to a Scope which contains the Entity Number <numin>. Several calls to the same <numscope> add Entities in this Scope, in this order. Error if <numin> is already declared in the Scope Warning : the declaration of the Scopes is assumed to be consistent, i.e. <numin> is not referenced from outside this Scope (not checked here)", py::arg("numscope"), py::arg("numin"));
cls_StepData_StepWriter.def("IsInScope", (Standard_Boolean (StepData_StepWriter::*)(const Standard_Integer) const) &StepData_StepWriter::IsInScope, "Returns True if an Entity identified by its Number is in a Scope", py::arg("num"));
cls_StepData_StepWriter.def("SendModel", [](StepData_StepWriter &self, const opencascade::handle<StepData_Protocol> & a0) -> void { return self.SendModel(a0); });
cls_StepData_StepWriter.def("SendModel", (void (StepData_StepWriter::*)(const opencascade::handle<StepData_Protocol> &, const Standard_Boolean)) &StepData_StepWriter::SendModel, "Sends the complete Model, included HEADER and DATA Sections Works with a WriterLib defined through a Protocol If <headeronly> is given True, only the HEADER Section is sent (used to Dump the Header of a StepModel)", py::arg("protocol"), py::arg("headeronly"));
cls_StepData_StepWriter.def("SendHeader", (void (StepData_StepWriter::*)()) &StepData_StepWriter::SendHeader, "Begins model header");
cls_StepData_StepWriter.def("SendData", (void (StepData_StepWriter::*)()) &StepData_StepWriter::SendData, "Begins data section; error if EndSec was not set");
cls_StepData_StepWriter.def("SendEntity", (void (StepData_StepWriter::*)(const Standard_Integer, const StepData_WriterLib &)) &StepData_StepWriter::SendEntity, "Send an Entity of the Data Section. If it corresponds to a Scope, also Sends the Scope informations and contained Items", py::arg("nument"), py::arg("lib"));
cls_StepData_StepWriter.def("EndSec", (void (StepData_StepWriter::*)()) &StepData_StepWriter::EndSec, "sets end of section; to be done before passing to next one");
cls_StepData_StepWriter.def("EndFile", (void (StepData_StepWriter::*)()) &StepData_StepWriter::EndFile, "sets end of file; error is EndSec was not set");
cls_StepData_StepWriter.def("NewLine", (void (StepData_StepWriter::*)(const Standard_Boolean)) &StepData_StepWriter::NewLine, "flushes current line; if empty, flushes it (defines a new empty line) if evenempty is True; else, skips it", py::arg("evenempty"));
cls_StepData_StepWriter.def("JoinLast", (void (StepData_StepWriter::*)(const Standard_Boolean)) &StepData_StepWriter::JoinLast, "joins current line to last one, only if new length is 72 max if newline is True, a new current line begins; else, current line is set to the last line (once joined) itself an can be completed", py::arg("newline"));
cls_StepData_StepWriter.def("Indent", (void (StepData_StepWriter::*)(const Standard_Boolean)) &StepData_StepWriter::Indent, "asks that further indentations will begin at position of entity first opening bracket; else they begin at zero (def) for each sublist level, two more blancks are added at beginning (except for text continuation, which must begin at true zero)", py::arg("onent"));
cls_StepData_StepWriter.def("SendIdent", (void (StepData_StepWriter::*)(const Standard_Integer)) &StepData_StepWriter::SendIdent, "begins an entity with an ident plus '=' (at beginning of line) entity ident is its Number given by the containing Model Warning : <ident> must be, either Number or Label, according LabelMode", py::arg("ident"));
cls_StepData_StepWriter.def("SendScope", (void (StepData_StepWriter::*)()) &StepData_StepWriter::SendScope, "sets a begin of Scope (ends this line)");
cls_StepData_StepWriter.def("SendEndscope", (void (StepData_StepWriter::*)()) &StepData_StepWriter::SendEndscope, "sets an end of Scope (on a separate line)");
cls_StepData_StepWriter.def("Comment", (void (StepData_StepWriter::*)(const Standard_Boolean)) &StepData_StepWriter::Comment, "sets a comment mark : if mode is True, begins Comment zone, if mode is False, ends Comment zone (if one is begun)", py::arg("mode"));
cls_StepData_StepWriter.def("SendComment", (void (StepData_StepWriter::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepData_StepWriter::SendComment, "sends a comment. Error if we are not inside a comment zone", py::arg("text"));
cls_StepData_StepWriter.def("SendComment", (void (StepData_StepWriter::*)(const Standard_CString)) &StepData_StepWriter::SendComment, "same as above but accepts a CString (ex.: '...' directly)", py::arg("text"));
cls_StepData_StepWriter.def("StartEntity", (void (StepData_StepWriter::*)(const TCollection_AsciiString &)) &StepData_StepWriter::StartEntity, "sets entity's StepType, opens brakets, starts param no to 0 params are separated by comma Remark : for a Multiple Type Entity (see Express ANDOR clause) StartComplex must be called before sending componants, then each 'Componant' must be send separately (one call to StartEntity for each one) : the Type which preceeds is then automaticaly closed. Once all the componants have been sent, EndComplex must be called, then and only then EndEntity", py::arg("atype"));
cls_StepData_StepWriter.def("StartComplex", (void (StepData_StepWriter::*)()) &StepData_StepWriter::StartComplex, "sends the start of a complex entity, which is a simple open bracket (without increasing braket level) It must be called JUST AFTER SendEntity and BEFORE sending componants, each one begins by StartEntity");
cls_StepData_StepWriter.def("EndComplex", (void (StepData_StepWriter::*)()) &StepData_StepWriter::EndComplex, "sends the end of a complex entity : a simple closed bracket It must be called AFTER sending all the componants and BEFORE the final call to EndEntity");
cls_StepData_StepWriter.def("SendField", (void (StepData_StepWriter::*)(const StepData_Field &, const opencascade::handle<StepData_PDescr> &)) &StepData_StepWriter::SendField, "Sends the content of a field, controlled by its descriptor If the descriptor is not defined, follows the description detained by the field itself", py::arg("fild"), py::arg("descr"));
cls_StepData_StepWriter.def("SendSelect", (void (StepData_StepWriter::*)(const opencascade::handle<StepData_SelectMember> &, const opencascade::handle<StepData_PDescr> &)) &StepData_StepWriter::SendSelect, "Sends a SelectMember, which cab be named or not", py::arg("sm"), py::arg("descr"));
cls_StepData_StepWriter.def("SendList", (void (StepData_StepWriter::*)(const StepData_FieldList &, const opencascade::handle<StepData_ESDescr> &)) &StepData_StepWriter::SendList, "Send the content of an entity as being a FieldList controlled by its descriptor. This includes start and end brackets but not the entity type", py::arg("list"), py::arg("descr"));
cls_StepData_StepWriter.def("OpenSub", (void (StepData_StepWriter::*)()) &StepData_StepWriter::OpenSub, "open a sublist by a '('");
cls_StepData_StepWriter.def("OpenTypedSub", (void (StepData_StepWriter::*)(const Standard_CString)) &StepData_StepWriter::OpenTypedSub, "open a sublist with its type then a '('", py::arg("subtype"));
cls_StepData_StepWriter.def("CloseSub", (void (StepData_StepWriter::*)()) &StepData_StepWriter::CloseSub, "closes a sublist by a ')'");
cls_StepData_StepWriter.def("AddParam", (void (StepData_StepWriter::*)()) &StepData_StepWriter::AddParam, "prepares adding a parameter (that is, adds ',' except for first one); normally for internal use; can be used to send a totally empty parameter (with no litteral value)");
cls_StepData_StepWriter.def("Send", (void (StepData_StepWriter::*)(const Standard_Integer)) &StepData_StepWriter::Send, "sends an integer parameter", py::arg("val"));
cls_StepData_StepWriter.def("Send", (void (StepData_StepWriter::*)(const Standard_Real)) &StepData_StepWriter::Send, "sends a real parameter (wroks with FloatWriter)", py::arg("val"));
cls_StepData_StepWriter.def("Send", (void (StepData_StepWriter::*)(const TCollection_AsciiString &)) &StepData_StepWriter::Send, "sends a text given as string (it will be set between '...')", py::arg("val"));
cls_StepData_StepWriter.def("Send", (void (StepData_StepWriter::*)(const opencascade::handle<Standard_Transient> &)) &StepData_StepWriter::Send, "sends a reference to an entity (its identifier with '#') REMARK 1 : a Null <val> is interpreted as 'Undefined' REMARK 2 : for an HAsciiString which is not recorded in the Model, it is send as its String Content, between quotes", py::arg("val"));
cls_StepData_StepWriter.def("SendBoolean", (void (StepData_StepWriter::*)(const Standard_Boolean)) &StepData_StepWriter::SendBoolean, "sends a Boolean as .T. for True or .F. for False (it is an useful case of Enum, which is built-in)", py::arg("val"));
cls_StepData_StepWriter.def("SendLogical", (void (StepData_StepWriter::*)(const StepData_Logical)) &StepData_StepWriter::SendLogical, "sends a Logical as .T. or .F. or .U. according its Value (it is a standard case of Enum for Step, and is built-in)", py::arg("val"));
cls_StepData_StepWriter.def("SendString", (void (StepData_StepWriter::*)(const TCollection_AsciiString &)) &StepData_StepWriter::SendString, "sends a string exactly as it is given", py::arg("val"));
cls_StepData_StepWriter.def("SendString", (void (StepData_StepWriter::*)(const Standard_CString)) &StepData_StepWriter::SendString, "sends a string exactly as it is given", py::arg("val"));
cls_StepData_StepWriter.def("SendEnum", (void (StepData_StepWriter::*)(const TCollection_AsciiString &)) &StepData_StepWriter::SendEnum, "sends an enum given by String (litteral expression) adds '.' around it if not done Remark : val can be computed by class EnumTool from StepData: StepWriter.SendEnum (myenum.Text(enumval));", py::arg("val"));
cls_StepData_StepWriter.def("SendEnum", (void (StepData_StepWriter::*)(const Standard_CString)) &StepData_StepWriter::SendEnum, "sends an enum given by String (litteral expression) adds '.' around it if not done", py::arg("val"));
cls_StepData_StepWriter.def("SendArrReal", (void (StepData_StepWriter::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepData_StepWriter::SendArrReal, "sends an array of real", py::arg("anArr"));
cls_StepData_StepWriter.def("SendUndef", (void (StepData_StepWriter::*)()) &StepData_StepWriter::SendUndef, "sends an undefined (optionnal absent) parameter (by '$')");
cls_StepData_StepWriter.def("SendDerived", (void (StepData_StepWriter::*)()) &StepData_StepWriter::SendDerived, "sends a 'Derived' parameter (by '*'). A Derived Parameter has been inherited from a Super-Type then redefined as being computed by a function. Hence its value in file is senseless.");
cls_StepData_StepWriter.def("EndEntity", (void (StepData_StepWriter::*)()) &StepData_StepWriter::EndEntity, "sends end of entity (closing bracket plus ';') Error if count of opened-closed brackets is not null");
cls_StepData_StepWriter.def("CheckList", (Interface_CheckIterator (StepData_StepWriter::*)() const) &StepData_StepWriter::CheckList, "Returns the check-list, which has received possible checks : for unknown entities, badly loaded ones, null or unknown references");
cls_StepData_StepWriter.def("NbLines", (Standard_Integer (StepData_StepWriter::*)() const) &StepData_StepWriter::NbLines, "Returns count of Lines");
cls_StepData_StepWriter.def("Line", (opencascade::handle<TCollection_HAsciiString> (StepData_StepWriter::*)(const Standard_Integer) const) &StepData_StepWriter::Line, "Returns a Line given its rank in the File", py::arg("num"));
cls_StepData_StepWriter.def("Print", (Standard_Boolean (StepData_StepWriter::*)(Standard_OStream &)) &StepData_StepWriter::Print, "writes result on an output defined as an OStream then clears it", py::arg("S"));

// Enums

}