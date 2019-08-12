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

void bind_Message_Gravity(py::module &);
void bind_Message_StatusType(py::module &);
void bind_Message_Status(py::module &);
void bind_endl(py::module &);
void bind_Message_Printer(py::module &);
void bind_Message_SequenceOfPrinters(py::module &);
void bind_Message_Messenger(py::module &);
void bind_Message_Alert(py::module &);
void bind_Message_ListOfAlert(py::module &);
void bind_Message_Report(py::module &);
void bind_Message_ProgressScale(py::module &);
void bind_Message_SequenceOfProgressScale(py::module &);
void bind_Message_ProgressIndicator(py::module &);
void bind_Message(py::module &);
void bind_Message_ExecStatus(py::module &);
void bind_Message_Msg(py::module &);
void bind_Message_ArrayOfMsg(py::module &);
void bind_Message_HArrayOfMsg(py::module &);
void bind_Message_Algorithm(py::module &);
void bind_Message_ListOfMsg(py::module &);
void bind_Message_ListIteratorOfListOfMsg(py::module &);
void bind_Message_MsgFile(py::module &);
void bind_Message_PrinterOStream(py::module &);
void bind_Message_ProgressSentry(py::module &);

PYBIND11_MODULE(Message, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");

bind_Message_Gravity(mod);
bind_Message_StatusType(mod);
bind_Message_Status(mod);
bind_endl(mod);
bind_Message_Printer(mod);
bind_Message_SequenceOfPrinters(mod);
bind_Message_Messenger(mod);
bind_Message_Alert(mod);
bind_Message_ListOfAlert(mod);
bind_Message_Report(mod);
bind_Message_ProgressScale(mod);
bind_Message_SequenceOfProgressScale(mod);
bind_Message_ProgressIndicator(mod);
bind_Message(mod);
bind_Message_ExecStatus(mod);
bind_Message_Msg(mod);
bind_Message_ArrayOfMsg(mod);
bind_Message_HArrayOfMsg(mod);
bind_Message_Algorithm(mod);
bind_Message_ListOfMsg(mod);
bind_Message_ListIteratorOfListOfMsg(mod);
bind_Message_MsgFile(mod);
bind_Message_PrinterOStream(mod);
bind_Message_ProgressSentry(mod);

}
