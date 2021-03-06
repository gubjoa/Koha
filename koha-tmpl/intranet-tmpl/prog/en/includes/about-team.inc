[%- BLOCK role -%]
  [%- SWITCH role.key -%]
    [%- CASE 'manager'               -%]Release manager
    [%- CASE 'manager_assistant'     -%]Release manager assistant
    [%- CASE 'qa_manager'            -%]Quality assurance manager
    [%- CASE 'qa'                    -%]Quality assurance team
    [%- CASE 'documentation'         -%]Documentation manager
    [%- CASE 'documentation_team'    -%]Documentation team
    [%- CASE 'translation'           -%]Translation manager
    [%- CASE 'translation_assistant' -%]Translation manager assistant
    [%- CASE 'te'                    -%]Topic expert
    [%- CASE 'bugwrangler'           -%]Bug wrangler
    [%- CASE 'maintainer'            -%]Release maintainer
    [%- CASE 'maintainer_assistant'  -%]Release maintainer assistant
    [%- CASE 'wiki'                  -%]Wiki curator
    [%- CASE 'ci'                    -%]Continuous integration manager
    [%- CASE 'packaging'             -%]Packaging manager
    [%- CASE 'packaging_assistant'   -%]Packaging manager assistant
    [%- CASE 'chairperson'           -%]Meetings chairperson
    [%- CASE 'newsletter'            -%]Newsletter editor
    [%- CASE 'mm'                    -%]Module maintainer
    [%- CASE 'vm'                    -%]Virtual machine maintainer
    [%- CASE 'database'              -%]Documentation specialist
    [%- CASE 'live_cd'               -%]Live CD maintainer
  [%- END -%]
[%- END -%]

[%- BLOCK person -%]
[% IF p.openhub %]<a href="[% p.openhub | url %]">[% p.name | html %]</a>[% ELSE %][% p.name | html %][% END %]
[%- END -%]

[%- BLOCK contributions -%]
[%- IF p.roles || p.notes -%]
<ul>
    [% FOREACH r IN p.roles %]<li>[% INCLUDE role role=r %] ([% r.value.join(', ') | html %])</li>[% END %]
    [% IF p.notes %]<li>[% p.notes | html %]</li>[% END %]
</ul>
[%- END -%]
[%- END -%]

[%- BLOCK team -%]
    <ul>

        [% IF v == 'release' %]
            <p>This is the team who were responsible for the initial release of your currently installed Koha version.</p>

            <li><strong>Release manager:</strong>
                [% INCLUDE person p=t.manager %]
            </li>

            [% IF t.manager_assistants %]
            <li><strong>Release manager assistants:</strong>
                <ul>
                    [% FOREACH a IN t.manager_assistants %]
                    <li>[% INCLUDE person p=a %]</li>
                    [% END %]
                </ul>
            </li>
            [% ELSIF t.manager_assistant %]
            <li><strong>Release manager assistant:</strong>
                [% INCLUDE person p=t.manager_assistant %]
            </li>
            [% END %]

        [% ELSE %]
            <p>This is the team who are responsible for the next release of Koha and the ongoing maintenance of your
            currently installed Koha version. They will be in these roles up until <strong>[% t.release_date | $KohaDates %]</strong>, when the next
            team will be elected.</p>

            <li><strong>Release maintainer:</strong>
                <ul>
                  [% FOREACH m IN t.maintainer %]
                    [% IF m.version == ( v - 0.01 ) %]
                      <li>[% INCLUDE person p=m %]</li>
                    [% END %]
                  [% END %]
                </ul>
            </li>
        [% END %]

        [% IF t.qa_manager %]
        <li><strong>Quality assurance manager:</strong>
            [% INCLUDE person p=t.qa_manager %]
        </li>
        [% END %]

        [% IF t.qa %]
        <li><strong>Quality assurance team:</strong>
            <ul>
                [% FOREACH qa IN t.qa %]
                <li>[% INCLUDE person p=qa %]</li>
                [% END %]
            </ul>
        </li>
        [% END %]

        [% IF t.documentation %]
        <li><strong>Documentation manager:</strong>
            [% INCLUDE person p=t.documentation %]
        </li>
        [% END %]

        [% IF t.documentation_team %]
        <li><strong>Documentation team:</strong>
            <ul>
                [% FOREACH doc_member IN t.documentation_team %]
                <li>[% INCLUDE person p=doc_member %]</li>
                [% END %]
            </ul>
        </li>
        [% END %]

        [% IF t.translation %]
        <li><strong>Translation manager:</strong>
            [% INCLUDE person p=t.translation %]
        </li>
        [% END %]

        [% IF t.packaging %]
        <li><strong>Packaging manager:</strong>
            [% INCLUDE person p=t.packaging %]
        </li>
        [% END %]

        [% IF t.ci %]
            [% IF t.ci.size == 1 %]
            <li><strong>Jenkins maintainer:</strong>
                [% INCLUDE person p=t.ci.0 %]
            </li>
            [% ELSE %]
            <li><strong>Jenkins maintainers:</strong>
                <ul>
                    [% FOREACH j IN t.ci %]
                    <li>[% INCLUDE person p=j %]
                    [% END %]
                </ul>
            </li>
            [% END %]
        [% END %]

        [% IF t.bugwrangler %]
        <li><strong>Bug wranglers:</strong>
            <ul>
                [% FOREACH bugwrangler IN t.bugwrangler %]
                <li>[% INCLUDE person p=bugwrangler %]</li>
                [% END %]
            </ul>
        </li>
        [% END %]

        [% IF v != 'release' %]

        <li><strong>Release manager:</strong>
            [% INCLUDE person p=t.manager %]
        </li>

        [% IF t.manager_assistants %]
        <li><strong>Release manager assistants:</strong>
            <ul>
                [% FOREACH a IN t.manager_assistants %]
                <li>[% INCLUDE person p=a %]</li>
                [% END %]
            </ul>
        </li>
        [% ELSIF t.manager_assistant %]
        <li><strong>Release manager assistant:</strong>
            [% INCLUDE person p=t.manager_assistant %]
        </li>
        [% END %]

        [% ELSE %]
        <li><strong>Release maintainers:</strong>
            <ul>
                [% FOREACH m IN t.maintainer %]
                <li>[% m.version | html %] - [% INCLUDE person p=m %]</li>
                [% END %]
            </ul>
        </li>
        [% END %]

    </ul>
[%- END -%]
