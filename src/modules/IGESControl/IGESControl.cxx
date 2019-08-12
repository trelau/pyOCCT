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

void bind_IGESControl_Reader(py::module &);
void bind_IGESControl_Writer(py::module &);
void bind_IGESControl_ActorWrite(py::module &);
void bind_IGESControl_AlgoContainer(py::module &);
void bind_IGESControl_Controller(py::module &);
void bind_IGESControl_IGESBoundary(py::module &);
void bind_IGESControl_ToolContainer(py::module &);

PYBIND11_MODULE(IGESControl, mod) {

py::module::import("OCCT.XSControl");
py::module::import("OCCT.Standard");
py::module::import("OCCT.IGESData");
py::module::import("OCCT.IFSelect");
py::module::import("OCCT.Transfer");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.IGESToBRep");
py::module::import("OCCT.Interface");
py::module::import("OCCT.ShapeExtend");

bind_IGESControl_Reader(mod);
bind_IGESControl_Writer(mod);
bind_IGESControl_ActorWrite(mod);
bind_IGESControl_AlgoContainer(mod);
bind_IGESControl_Controller(mod);
bind_IGESControl_IGESBoundary(mod);
bind_IGESControl_ToolContainer(mod);

}
