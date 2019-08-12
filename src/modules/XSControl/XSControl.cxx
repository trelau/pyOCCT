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

void bind_XSControl_Reader(py::module &);
void bind_XSControl_Controller(py::module &);
void bind_XSControl_TransferWriter(py::module &);
void bind_XSControl_WorkSession(py::module &);
void bind_XSControl_SelectForTransfer(py::module &);
void bind_XSControl(py::module &);
void bind_XSControl_ConnectedShapes(py::module &);
void bind_XSControl_FuncShape(py::module &);
void bind_XSControl_Functions(py::module &);
void bind_XSControl_SignTransferStatus(py::module &);
void bind_XSControl_TransferReader(py::module &);
void bind_XSControl_Utils(py::module &);
void bind_XSControl_Vars(py::module &);
void bind_XSControl_Writer(py::module &);

PYBIND11_MODULE(XSControl, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.IFSelect");
py::module::import("OCCT.Interface");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.Transfer");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.Message");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.gp");

bind_XSControl_Reader(mod);
bind_XSControl_Controller(mod);
bind_XSControl_TransferWriter(mod);
bind_XSControl_WorkSession(mod);
bind_XSControl_SelectForTransfer(mod);
bind_XSControl(mod);
bind_XSControl_ConnectedShapes(mod);
bind_XSControl_FuncShape(mod);
bind_XSControl_Functions(mod);
bind_XSControl_SignTransferStatus(mod);
bind_XSControl_TransferReader(mod);
bind_XSControl_Utils(mod);
bind_XSControl_Vars(mod);
bind_XSControl_Writer(mod);

}
