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

void bind_STEPControl_StepModelType(py::module &);
void bind_STEPControl_ActorWrite(py::module &);
void bind_STEPControl_Controller(py::module &);
void bind_STEPControl_Reader(py::module &);
void bind_STEPControl_Writer(py::module &);
void bind_STEPControl_ActorRead(py::module &);

PYBIND11_MODULE(STEPControl, mod) {

py::module::import("OCCT.Transfer");
py::module::import("OCCT.Standard");
py::module::import("OCCT.StepShape");
py::module::import("OCCT.StepGeom");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.STEPConstruct");
py::module::import("OCCT.XSControl");
py::module::import("OCCT.Interface");
py::module::import("OCCT.IFSelect");
py::module::import("OCCT.StepData");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.StepRepr");
py::module::import("OCCT.gp");
py::module::import("OCCT.TransferBRep");
py::module::import("OCCT.StepBasic");
py::module::import("OCCT.StepToTopoDS");

bind_STEPControl_StepModelType(mod);
bind_STEPControl_ActorWrite(mod);
bind_STEPControl_Controller(mod);
bind_STEPControl_Reader(mod);
bind_STEPControl_Writer(mod);
bind_STEPControl_ActorRead(mod);

}
