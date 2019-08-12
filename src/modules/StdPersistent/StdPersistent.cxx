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

void bind_StdPersistent_TopoDS(py::module &);
void bind_StdPersistent_HArray1OfShape1(py::module &);
void bind_StdPersistent_HArray1(py::module &);
void bind_StdPersistent(py::module &);
void bind_StdPersistent_DataXtd(py::module &);
void bind_StdPersistent_DataXtd_Constraint(py::module &);
void bind_StdPersistent_DataXtd_PatternStd(py::module &);
void bind_StdPersistent_Naming(py::module &);
void bind_StdPersistent_PPrsStd(py::module &);
void bind_StdPersistent_TopLoc(py::module &);

PYBIND11_MODULE(StdPersistent, mod) {

py::module::import("OCCT.StdObjMgt");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.StdObject");
py::module::import("OCCT.StdLPersistent");
py::module::import("OCCT.TDataXtd");
py::module::import("OCCT.gp");
py::module::import("OCCT.TNaming");
py::module::import("OCCT.TDF");
py::module::import("OCCT.TopLoc");

bind_StdPersistent_TopoDS(mod);
bind_StdPersistent_HArray1OfShape1(mod);
bind_StdPersistent_HArray1(mod);
bind_StdPersistent(mod);
bind_StdPersistent_DataXtd(mod);
bind_StdPersistent_DataXtd_Constraint(mod);
bind_StdPersistent_DataXtd_PatternStd(mod);
bind_StdPersistent_Naming(mod);
bind_StdPersistent_PPrsStd(mod);
bind_StdPersistent_TopLoc(mod);

}
