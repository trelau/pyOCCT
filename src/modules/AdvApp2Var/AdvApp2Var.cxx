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

void bind_AdvApp2Var_CriterionType(py::module &);
void bind_AdvApp2Var_CriterionRepartition(py::module &);
void bind_AdvApp2Var_Context(py::module &);
void bind_AdvApp2Var_EvaluatorFunc2Var(py::module &);
void bind_AdvApp2Var_Patch(py::module &);
void bind_AdvApp2Var_SequenceOfPatch(py::module &);
void bind_AdvApp2Var_Network(py::module &);
void bind_AdvApp2Var_Node(py::module &);
void bind_AdvApp2Var_SequenceOfNode(py::module &);
void bind_AdvApp2Var_Iso(py::module &);
void bind_AdvApp2Var_Strip(py::module &);
void bind_AdvApp2Var_SequenceOfStrip(py::module &);
void bind_AdvApp2Var_Framework(py::module &);
void bind_AdvApp2Var_ApproxAFunc2Var(py::module &);
void bind_AdvApp2Var_ApproxF2var(py::module &);
void bind_AdvApp2Var_Criterion(py::module &);
void bind_mdnombr_1_(py::module &);
void bind_minombr_1_(py::module &);
void bind_maovpar_1_(py::module &);
void bind_maovpch_1_(py::module &);
void bind_mlgdrtl_1_(py::module &);
void bind_mmjcobi_1_(py::module &);
void bind_mmcmcnp_1_(py::module &);
void bind_mmapgss_1_(py::module &);
void bind_mmapgs0_1_(py::module &);
void bind_mmapgs1_1_(py::module &);
void bind_mmapgs2_1_(py::module &);
void bind_AdvApp2Var_Data(py::module &);
void bind_AdvApp2Var_MathBase(py::module &);
void bind_AdvApp2Var_SysBase(py::module &);

PYBIND11_MODULE(AdvApp2Var, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.AdvApprox");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TColGeom");

bind_AdvApp2Var_CriterionType(mod);
bind_AdvApp2Var_CriterionRepartition(mod);
bind_AdvApp2Var_Context(mod);
bind_AdvApp2Var_EvaluatorFunc2Var(mod);
bind_AdvApp2Var_Patch(mod);
bind_AdvApp2Var_SequenceOfPatch(mod);
bind_AdvApp2Var_Network(mod);
bind_AdvApp2Var_Node(mod);
bind_AdvApp2Var_SequenceOfNode(mod);
bind_AdvApp2Var_Iso(mod);
bind_AdvApp2Var_Strip(mod);
bind_AdvApp2Var_SequenceOfStrip(mod);
bind_AdvApp2Var_Framework(mod);
bind_AdvApp2Var_ApproxAFunc2Var(mod);
bind_AdvApp2Var_ApproxF2var(mod);
bind_AdvApp2Var_Criterion(mod);
bind_mdnombr_1_(mod);
bind_minombr_1_(mod);
bind_maovpar_1_(mod);
bind_maovpch_1_(mod);
bind_mlgdrtl_1_(mod);
bind_mmjcobi_1_(mod);
bind_mmcmcnp_1_(mod);
bind_mmapgss_1_(mod);
bind_mmapgs0_1_(mod);
bind_mmapgs1_1_(mod);
bind_mmapgs2_1_(mod);
bind_AdvApp2Var_Data(mod);
bind_AdvApp2Var_MathBase(mod);
bind_AdvApp2Var_SysBase(mod);

}
