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

void bind_BlendFunc_SectionShape(py::module &);
void bind_BlendFunc(py::module &);
void bind_BlendFunc_Corde(py::module &);
void bind_BlendFunc_Chamfer(py::module &);
void bind_BlendFunc_ChamfInv(py::module &);
void bind_BlendFunc_ChAsym(py::module &);
void bind_BlendFunc_ChAsymInv(py::module &);
void bind_BlendFunc_Tensor(py::module &);
void bind_BlendFunc_ConstRad(py::module &);
void bind_BlendFunc_ConstRadInv(py::module &);
void bind_BlendFunc_CSCircular(py::module &);
void bind_BlendFunc_CSConstRad(py::module &);
void bind_BlendFunc_EvolRad(py::module &);
void bind_BlendFunc_EvolRadInv(py::module &);
void bind_BlendFunc_Ruled(py::module &);
void bind_BlendFunc_RuledInv(py::module &);

PYBIND11_MODULE(BlendFunc, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Convert");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.gp");
py::module::import("OCCT.math");
py::module::import("OCCT.Blend");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.Law");

bind_BlendFunc_SectionShape(mod);
bind_BlendFunc(mod);
bind_BlendFunc_Corde(mod);
bind_BlendFunc_Chamfer(mod);
bind_BlendFunc_ChamfInv(mod);
bind_BlendFunc_ChAsym(mod);
bind_BlendFunc_ChAsymInv(mod);
bind_BlendFunc_Tensor(mod);
bind_BlendFunc_ConstRad(mod);
bind_BlendFunc_ConstRadInv(mod);
bind_BlendFunc_CSCircular(mod);
bind_BlendFunc_CSConstRad(mod);
bind_BlendFunc_EvolRad(mod);
bind_BlendFunc_EvolRadInv(mod);
bind_BlendFunc_Ruled(mod);
bind_BlendFunc_RuledInv(mod);

}
